//4-polygon
#include<bits/stdc++.h>
using namespace std;
long long ans=0;
int a[7050];
int b[7050];
bool bl[100];
int sm=0,n;
void f(int x,int mx){
	if(x>n){
		if(sm>2*mx)ans++;
		return;
	}
	sm+=a[x];
	f(x+1,max(mx,a[x]));
	sm-=a[x];
	f(x+1,mx);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int mx=-1;
	bool fl=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		mx=max(mx,a[i]);
		if(a[i]!=a[1])fl=0;
	}
	if(fl||mx<=1){
		ans=0;
		b[1]=1;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j>=1;j--)
				b[j]=(b[j]+b[j-1])%998244353;
		for(int i=1;i<=n-2;i++)
			ans=(ans+b[i])%998244353;
		printf("%lld",ans);
	}
	else if(n<=32){
		ans=0;
		f(1,0);
		printf("%lld",ans);
	}
	else cout<<0;
	return 0;
}
