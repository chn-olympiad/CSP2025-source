#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,a,b,c,mx=-1;
	cin>>n;
	if(n==3){
		cin>>a>>b>>c;
		if(a+b+c>max(a,max(b,c)))cout<<1;
	}
	for(int i=1;i<=n;i++){
		cin>>a;
		mx=max(a,mx);
	}
	if(mx==1)cout<<(n*(n-1)*(n-2))%998244;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
