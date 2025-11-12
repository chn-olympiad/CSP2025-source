#include <bits/stdc++.h>
using namespace std;
int n,a[5001];
long long ans;
void FOUND(int point,int maxvalue,int addvalue){
	for(int k=point+1;k<=n;++k){
		if((addvalue+a[k])>(2*max(maxvalue,a[k]))) ++ans,ans%=998244353;
		FOUND(k,max(maxvalue,a[k]),addvalue+a[k]);
	}
}
long long C(int __UP,int __DOWN){
	long long ans=1;
	long long CS=__UP;
	for(int i=__DOWN;i>__DOWN-__UP;--i){
		ans*=i;
		if(ans%CS==0)ans/=CS,--CS;
	}
	for(int i=CS;i>1;--i){
		ans/=i;
	}
	return ans; 
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool ALL_IS_1=true;
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		if(a[i]!=1)ALL_IS_1=false;
	}
	if(ALL_IS_1){
		for(int i=3;i<=n;++i){
			ans+=(C(i,n)%998244353);
			ans%=998244353;
		}
	}//C(m,n),mFROM3TOn
	else{
		sort(a+1,a+n+1);
		for(int i=1;i<n;++i)
			for(int j=i+1;j<=n;++j)
				FOUND(j,a[j],a[i]+a[j]);
	}
	cout<<ans;	
	return 0;
}
