#include<bits/stdc++.h>
using namespace std;
int n,a[5010],s,d;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	cin>>a[1]>>a[2]>>a[3];
	s=a[1]+a[2]+a[3];
	d=max(max(a[1],a[2]),a[3]);
	if(s>2*d)cout<<1;
	else cout<<0;
	return 0;
}
