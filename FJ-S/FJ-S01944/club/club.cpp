#include<bits/stdc++.h> 

using namespace std;

const int N = 1e5+10;


int n; //记录人数 

int T;

struct node{
	int feel,num;
}sort_people[N];

int people[N][5];
int club[5];
int mp_people[N][5]; //用于映射：每一个学生报的是什么社团
int mp_club[5]; //用于映射：每一个社团人数 

struct fa{
	int favo,num;
}mp_favorite[N]; //用于映射：每个人最喜欢的社团值


bool cmp(node x,node y){ //让其依照最佳意愿进行排序 
	return x.feel > y.feel; 
} 


bool fa_cmp1(fa x,fa y){
	return x.favo > y.favo;
} 

int find(int x,int k){ //第几个人，调剂到第几个 
	if(k>3){return 0;}
	int flag = 0; //记录这个人是否分配到了一个社团 
	int one_feel = 0;//记录下当前这个人收获的满意度 
	//每个人都要报，且优先报自己最喜欢的 
	if(mp_club[mp_people[x][k]]+1<=n/2){//该社团还没有满员 
		mp_club[mp_people[x][k]]++; //该社团加一个人 (用数组第一项记录该社团当前人数）
		flag = 1;//已加入社团 
	} 
	else{ //满员了又该怎么处理 
		find(x,k+1); //调剂到下一个 
	}
	
	if(flag==1){
		one_feel = people[x][k];
	} 
	
	return one_feel;

}


int main(){
	
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	scanf("%d",&T);
	
	for(int i=1;i<=T;i++){
		
		memset(people,0,sizeof(people));
		memset(club,0,sizeof(club));
		memset(mp_people,0,sizeof(mp_people));
		memset(mp_club,0,sizeof(mp_club));
		 
		scanf("%d",&n);
		int nice1 = 0; //初始化 
		int nice2 = 0;
		
		for(int i=1;i<=n;i++){ //注意这里从1开始循环读入 
			memset(sort_people,0,sizeof(sort_people));
			for(int j=1;j<=3;j++){
				scanf("%d",&sort_people[j].feel);
				sort_people[j].num = j;
			} 
			mp_favorite[i].num = i; //记录下当前这个人的序号用于后续判断是否满足他的性价比最高 
			sort(sort_people+1,sort_people+4,cmp);
				
			for(int k=1;k<=3;k++){
				people[i][k] = sort_people[k].feel; //实现每个人的好感度都是从高到低  
				mp_people[i][k] = sort_people[k].num; //记录每个人对123社团的排名顺序 
				mp_people[i][0] = mp_people[i][1]; //记好感度最高的作为默认社团选择 
				mp_favorite[i].favo = people[i][1]; //从最易满足的性价比排序
			}
		} 
		
		
		sort(mp_favorite+1,mp_favorite+n+1,fa_cmp1);

		for(int i=1;i<=n;i++){
			int goal = mp_favorite[i].num; //记录当前的最佳客户 
			nice1 += find(goal,1); //优先满足他的最佳喜好 
		}
		
		memset(mp_club,0,sizeof(club));
		for(int i=n;i>=1;i--){
			int goal = mp_favorite[i].num;
			nice2 += find(goal,1);
		}

		cout<<max(nice1,nice2)<<endl;
}
	
	return 0;
}
