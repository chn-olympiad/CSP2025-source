#include<iostream>
#include<vector>
using namespace std;

int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		
		if(false){//原输入并计算0数量的备份，现已合并
		
		 
		
		//输入 
		vector<vector<int>> c(n+1,vector<int>(4,0));
		vector<vector<int>> m(n+1,vector<int>(4,0));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>c[i][j];
			}
			int mc=max(max(c[i][1],c[i][2]),c[i][3]);
			for(int j=1;j<=3;j++){
				m[i][j]=mc-c[i][j];
			}
		}
		
		//找到0超了的那组
		int o[4]={0};
		bool f[4]={0};
		for(int i=1;i<=n;i++){//每个检查一次 
			for(int j=1;j<=3;j++){//检查三个数字哪个是0 
				if(m[i][j]==0){
					o[j]++;//是0的话，就增加那个位置0的数量 
					if(o[j]>n/2) f[j]=true;//如果超过了n/2就要制裁ccf 
					break;		
				}
			}
		}
		}
		
		vector<vector<int>> c(n+1,vector<int>(4,0));
		vector<vector<int>> m(n+1,vector<int>(4,0));
		int o[4]={0};
		bool f[4]={0};
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&c[i][j]);
			}
			int mc=max(max(c[i][1],c[i][2]),c[i][3]);
			for(int j=1;j<=3;j++){
				m[i][j]=mc-c[i][j];
				if(m[i][j]==0){
					o[j]++;//是0的话，就增加那个位置0的数量 
					if(o[j]>n/2) f[j]=true;//如果超过了n/2就要制裁ccf 
					break;		
				}
			}
		}
		
		int spd=0;//想要合法要牺牲多少 
		for(int i=1;i<=3;i++){//看看哪个要被制裁
			if(f[i]){//需要被制裁 
				//cout<<"will be pop:"<<i<<endl;
				int a1=(i)%3+1,a2=(i+1)%3+1; //另外两个能放人的 
				vector<int> s(n+1);//存放制裁花费
				for(int j=1;j<=n;j++){
					s[j]=min(m[j][a1],m[j][a2]);//取小值 
				}
				vector<bool> die(n+1,true);//被制裁就不能再死了
				
				if(false){//尝试使用队列优化但是好像没有用 
				/*queue<int> min_nums;
				int k=o[i]-n/2;
				while(k){
					for(int j=1;j<=n;j++){//找出最小的几个挡灾
						if(s[j]<min_nums.back() && die[j] && m[j][i]==0){
							min_nums.push(s[j]);
						}
					}
					if(min_nums.size()<k){
						k-=min_nums.size();
						while(!min_nums.empty()){
							spd+=min_nums.front();
							min_nums.pop();
						}
					}
					else{
						for(int p=0;p<k;p++){
							spd+=min_nums.front();
							min_nums.pop();
						}
					}
				}*/
				}
				
				for(int j=1;j<=o[i]-n/2;j++){//找出最小的几个挡灾
					int min=222222;
					int mink; 
					for(int k=1;k<=n;k++){
						if(s[k]<min && die[k] && m[k][i]==0){//最小 没死 抢位置 
							mink=k;
							min=s[k];
						}
					}
					die[mink]=false;
					//cout<<min<<" is die\n";
					spd+=min;//牺牲的钱加上这个 
				}
				//制裁完毕，退出循环
				break; 
			}
		}
		
		//计算最理想数据
		 int sum=0;
		 for(int i=1;i<=n;i++){
		 	sum+=max(c[i][1],max(c[i][2],c[i][3]));
		 	//cout<< max(c[i][1],max(c[i][2],c[i][3]))<<endl;
		 }
		 
		 //调试输出
		 //cout<<sum<<" "<<spd<<endl;
		  
		 //理想-牺牲 就是答案 
		 printf("%d\n",sum-spd);
	}
	return 0;
}
