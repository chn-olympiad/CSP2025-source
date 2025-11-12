#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
struct node{
		int val1,val2,val3;
}a[N];
int t,n,ans;
void dfs(int id,int sum,int num1,int num2,int num3){
	if(id==n+1){
		if(num1<=n/2&&num2<=n/2&&num3<=n/2)
			ans=max(ans,sum);
		return ;
	}
	dfs(id+1,sum+a[id].val1,num1+1,num2,num3);
	dfs(id+1,sum+a[id].val2,num1,num2+1,num3);
	dfs(id+1,sum+a[id].val3,num1,num2,num3+1);
	return ;
}
bool cmp(node x,node y){
	return x.val1>y.val1;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		int e=1;
		for(int i=1;i<=n;i++){
			cin>>a[i].val1>>a[i].val2>>a[i].val3;
			if(a[i].val2!=0||a[i].val3!=0) e=0;
		}
		if(e){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++)
				ans+=a[i].val1;
		}
		else dfs(1,0,0,0,0);
		cout<<ans<<"\n";
	}
	return 0;
}
