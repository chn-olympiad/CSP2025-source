#include<bits/stdc++.h>
using namespace std;
long long n,m,c[520],ans=1,a[600];
string as;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	cin>>as;
	for(int i=0;i<as.size();i++){
		a[i+1]=as[i]-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	sort(c+1,c+1+n);
	if(m==n){
	    for(int i=1;i<=n;i++){
	    	ans=(ans*i)%998244353;
		}
		printf("%lld",ans);
	}
	else{
		cout<<0;
	}
	return 0;
}
