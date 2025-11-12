#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct sc{
	ll a1,a2,a3;
}a[100001];

ll t,n,ans;

void dfs(int k,int ma,int num1,int num2,int num3){
	if(num1>n/2||num2>n/2||num3>n/2){
		return;
	}
	if(k>n){
		if(ans<ma){
			ans=ma;
		}
		return;
	}
	dfs(k+1,ma+a[k].a1,num1+1,num2,num3);
	dfs(k+1,ma+a[k].a2,num1,num2+1,num3);
	dfs(k+1,ma+a[k].a3,num1,num2,num3+1);
	return;
} 

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
		}
		dfs(1,0,0,0,0); 
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
