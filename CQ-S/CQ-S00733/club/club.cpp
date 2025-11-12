#include<bits/stdc++.h>
using namespace std;
struct sss{
	int a1;
	int a2;
	int a3;
}a[100001];
int sum,ans=0,n;
void dfs(int now,int sum1,int sum2,int sum3,int step){
	if(now>n){
		ans=max(ans,step);
		return;
	}
	if(sum1<sum){
		dfs(now+1,sum1+1,sum2,sum3,step+a[now].a1);
	}
	if(sum2<sum){
		dfs(now+1,sum1,sum2+1,sum3,step+a[now].a2);
	}
	if(sum3<sum){
		dfs(now+1,sum1,sum2,sum3+1,step+a[now].a3);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int k=1;k<=t;k++){
		cin>>n;
		ans=0;
		int sum1=0,sum2=0,sum3=0;
		sum=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
		}
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}

