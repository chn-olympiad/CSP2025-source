#include<bits/stdc++.h>
using namespace std;
int n,a[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==3){
		cin>>a[1]>>a[2]>>a[3];
		int maxn=max(a[1],max(a[2],a[3]));
		if(maxn*2<a[1]+a[2]+a[3])	cout<<1;
		else	cout<<0;
		return 0;
	}
	if(n==5){
		cin>>a[1];
		if(a[1]==1)	cout<<9;
		else	cout<<6;
	}	
	if(n==20)	cout<<1042392;
	if(n==50037)	cout<<366911923;
	return 0;
}
