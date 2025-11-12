#include<fstream>
using namespace std;
ifstream cin("club.in");
ofstream cout("club.out");
struct mmyd{
	int a1;
	int a2;
	int a3;
}myd[100001];
int minn=0;
int n;
int dfs(int a,int sum){
	if(a>n){
		if(sum>minn){
			minn=sum;
			
		}
		return 0;
	}
	for(int i=1;i<=3;i++){
		if(i==1){
			sum+=myd[a].a1;
			dfs(a+1,sum);
			sum-=myd[a].a1;
		}
		if(i==2){
			sum+=myd[a].a2;
			dfs(a+1,sum);
			sum-=myd[a].a2;
		}
		if(i==3){
			sum+=myd[a].a3;
			dfs(a+1,sum);
			sum-=myd[a].a3;
		}
	}
	return 0;
}
int main(){
	int T;
	cin>>T;
	while(T--){
		minn=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>myd[i].a1>>myd[i].a2>>myd[i].a3;
		}
		dfs(1,0);
		cout<<minn<<endl;
	}
	
	cin.close();
	cout.close();
return 0;
}
