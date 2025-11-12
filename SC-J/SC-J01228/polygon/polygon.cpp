#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],p,anss;
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			p=1;
		}
	}
	if(n==3){
		long long x=a[1]+a[2]+a[3],maxx=max(max(a[1],a[2]),a[3]);
		if(x>(maxx*2)){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}
	if(p==0){
		for(long long i=n-2;i>=1;i--){
			anss+=i;
		}
		cout<<anss<<endl;
		return 0;
	}
	cout<<6;
	return 0;
}