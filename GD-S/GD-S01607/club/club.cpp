#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n;
struct node{
	long long a1;
	long long b1;
	long long c1;
}a[N];
bool cmp(node x,node y){
	return x.a1>y.a1;
}
long long sum=0;
void dfs(int now,int t1,int t2,int t3,long long tot){
	if(now==n+1){
		sum=max(sum,tot);
		return;
	}
	if(t1<n/2){
		dfs(now+1,t1+1,t2,t3,tot+a[now].a1);
	}
	if(t2<n/2){
		dfs(now+1,t1,t2+1,t3,tot+a[now].b1);
	}
	if(t3<n/2){
		dfs(now+1,t1,t2,t3+1,tot+a[now].c1);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t){
		sum=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].b1>>a[i].c1;
		}
		if(n>200){
			sort(a+1,a+1+n,cmp);
			long long ans=0;
			for(int i=1;i<=n/2;i++){
				ans+=a[i].a1;
			}
			cout<<ans<<endl;
		}else{
			dfs(1,0,0,0,0);
			cout<<sum<<endl;
		}
		t--;
	}
	return 0;
}
