#include<bits/stdc++.h>
using namespace std;
long long m;
long long a[1000000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>m;
	long long x=0,maxn=0;
	for(int i=1;i<=m;i++){
		cin>>a[i];
		x+=a[i];
		maxn=max(a[i],maxn);
	}
	cout<<x<<" "<<maxn<<" ";
	if(maxn*2<x){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
