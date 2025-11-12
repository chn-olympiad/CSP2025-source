#include<iostream>
using namespace std;
int n;
int num=0;
int a[5004];
void dfs(int step,int maxnum,int sum,int cnt){
	if(step>n){
		if(cnt>=3&&sum>2*maxnum){
			num++;
		}
		return;
	}
	if(a[step]>maxnum){
		dfs(step+1,a[step],sum+a[step],cnt+1);
		dfs(step+1,maxnum,sum,cnt);
	}else{
		dfs(step+1,maxnum,sum+a[step],cnt+1);
		dfs(step+1,maxnum,sum,cnt);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0,0);
	cout<<num<<endl;
	return 0;
}
