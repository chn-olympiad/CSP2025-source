#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	if(n<3){
		int l;
		for(int i=0;i<n;i++) cin>>l;
		cout<<0;
	}
	else if(n==3){
		int a,b,c;
		cin>>a>>b>>c;
		int mx=max(max(a,b),c);
		cout<<(mx*2<a+b+c);
	}
	else{
		long long j=1,a;
		for(int i=1;i<=n;i++){
			cin>>a;
			j=j*i%998244353;
		}
		cout<<j;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
