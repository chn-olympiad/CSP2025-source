#include<bits/stdc++.h>
using namespace std;
const int p=998244353;
int n;
long long ans=0;
int a[5005];
bool used[5005];
long long ksm(long long a,long long b){
	long long s=1;
	while(b>=1){
		if(b%2) s=(s*a)%p;
		a=(a*a)%p;
		b/=2;
	}
	return s;
}
void tepan(){
	for(int i=3;i<=n;i++){
		long long s=1,s1=1,s2=1;
		for(int j=1;j<=n;j++) s=(s*j)%p;
		for(int j=1;j<=n-i;j++) s1=(s1*j)%p;
		for(int j=1;j<=i;j++) s2=(s2*j)%p;
		s=(((s*ksm(s1,p-2))%p)*ksm(s2,p-2))%p;
		ans=(ans+s)%p;
	}
	cout<<ans<<endl;
}
void dfs(int l,int x,int m,int sum,int ma){
	if(x==m){
		if(sum>ma*2) ans++;
		return;
	}
	for(int i=l;i<=n;i++){
		int t;
		t=max(ma,a[i]);
		dfs(i+1,x+1,m,sum+a[i],t);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]<=a[3]) cout<<0<<endl;
		else cout<<1<<endl;
		return 0;
	}
	if(a[1]==1&&a[n]==1){
		tepan();
		return 0;
	}
	for(int i=3;i<=n;i++) dfs(1,0,i,0,0);
	cout<<ans<<endl;
}
