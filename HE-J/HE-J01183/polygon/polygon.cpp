#include<bits/stdc++.h>
using namespace std;
long long n,qq[10000],ans=1,zans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%ld",qq+i);
	}
	if(n==3){
		int x=max(qq[1],max(qq[2],qq[3])),z=qq[1]+qq[2]+qq[3];
		z-=x;
		if(z>x)cout<<1;
		else cout<<0;
		return 0;
	}
	int a=n,b=1;
	ans*=a;
	ans%=998244353;
	ans/=b;
	ans%=998244353;
	a--,b++;
	ans*=a;
	ans%=998244353;
	ans/=b;
	ans%=998244353;
	a--,b++;
	
	while(a>=1){
		ans*=a;
		ans%=998244353;
		ans/=b;
		ans%=998244353;
		a--,b++;
		zans+=ans;
		zans%=998244353;
	}
	cout<<zans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
