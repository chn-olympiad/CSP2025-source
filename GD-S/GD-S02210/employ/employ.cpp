//employ
#include<bits/stdc++.h>
using namespace std;
long long n,m,s[1001],c[1001],n0;
char a;
unsigned long long ans,p=1;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
		s[i]=a-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(!c[i]){
			n0++;
		}
	} 
	sort(c+1,c+n+1);
	for(int i=n0+1;i<=n;i++){
		if(c[i]-n0<=0){
			n0++;
		}
		else break;
	}
	p=1;
	for(int i=n;i>=n-m+2;i--){
		p=p*i;
		p=p%998244353;
	}
	for(int i=n-m+1;i>=1;i--){
		p=p*i;
		p=p%998244353;
		ans+=p;
		ans=ans%998244353;
	}
	cout<<ans;
	return 0;
}
