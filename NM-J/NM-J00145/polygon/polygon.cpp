#include<bits/stdc++.h>

using namespace std;
long long k[6000];

long long n,ans=0;
long long node=998244353;
void check(long long a,long long b,long long c,long long d){
	if(a==n+1){
		if(c>b*2&&d>=3)ans++;

		return;
	}check(a+1,max(b,k[a]),c+k[a],d+1);
	check(a+1,b,c,d);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>k[i];
	}check(1,0,0,0);
	cout<<ans%node;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

