//GZ-S00181 毕节梁才学校 张静峰
#include<bits/stdc++.h>
using namespace std ;
typedef long long LL;
/*
	家妈的我真的遭求不住了 ,写到一半给我卡弹出去了，重写！！！！！！

	这题tmd就是个缝合怪
	初看：
		贪心+并查集+模拟+枚举
	先写低配版（原因：k的大小比较小,可以尝试用dfs搜索）:(完成）
		并查集+贪心
		
	接着，用dfs枚举建每一座城，每一种情况运行一次，
	（剪枝）
	若加的数量已经超过不加 
	
	我靠 竟然写完了！！！！ 
*/
//输入
int n,m,k;
LL cnt=0;
struct E {
	int x,y,mo;
} e[1100010];
int w[10][10010];

bool cmp(E a,E b) {
	return a.mo<b.mo;
}

int p[110010];//并查集

int find(int x) {
	if(p[x]!=x) {
		p[x]=find(p[x]);
	}
	return p[x];
}

void work(vector<int> q,LL add) {
	//从这里开始可以封装成函数
	int c=q.size();
	//开始加路
	int now=0;//下表 
	for(int i=0;i<q.size();i++){
		int id=q[i];
		for(int j=1;j<=n;j++){
			now++;
			e[m+now]=(E){j,n+id,w[id][j]};
		}
	} 
	
	sort(e+1,e+1+m+now,cmp);//排好序了
	for(int i=1; i<=n+c; i++) {
		p[i]=i;
	}
	for(int i=1; i<=m+now; i++) {
		int x=e[i].x;
		int y=e[i].y;
		int zx=find(x);
		int zy=find(y);
		if(zx!=zy) {
			p[zx]=zy;
			add+=e[i].mo;
			//cout<<x<<' '<<y<<endl;
		}
	}
	//cout<<"===="<<add<<endl;
	cnt=min(cnt,add);
}
// dfs


vector<int> v;//记录 
int s[20];

bool cmp2(int a,int b){
	return w[a][0]>w[b][0];
} 

void cut(){//排序剪枝 对s 数组进行排序 
	sort(s+1,s+k+1,cmp2);
}

void dfs(int u,LL num){//在建第几城,建造总费用 
	//cout<<u<<endl; 
	if(num>cnt) return ;//剪枝 
	if(u==k+1){
		work(v,num);
		return ;
	} 
	dfs(u+1,num);//不建
	v.push_back(s[u]);
	dfs(u+1,num+w[s[u]][0]);
	v.pop_back() ;
} 

int main () {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1; i<=n; i++) {
		p[i]=i;
	}
	for(int i=1; i<=m; i++) { //存路
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		e[i]=(E) {
			x,y,z
		};
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>w[i][j];
		}
	}
	for(int i=1;i<=k;i++){
		s[i]=i;
	}
	//排序剪枝
	cut(); 
	 
	sort(e+1,e+1+m,cmp);//排好序了
	
	for(int i=1; i<=m; i++) {
		int x=e[i].x;
		int y=e[i].y;
		int zx=find(x);
		int zy=find(y);
		if(zx!=zy) {
			p[zx]=zy;
			cnt+=e[i].mo;
			//cout<<x<<' '<<y<<endl;
		}
	}
	
	dfs(1,0);
	cout<<cnt;
	return 0 ;
}

