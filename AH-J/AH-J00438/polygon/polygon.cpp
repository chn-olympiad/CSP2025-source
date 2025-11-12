#include <bits/stdc++.h>
using namespace std;
int a[25];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,a,b,c,sum=0;
	cin>>n>>a>>b>>c;
	sum=a+b+c;
	if(sum>a*2 && sum>b*2 && sum>b*2) cout<<1;
	else cout<<0;
	return 0;
}
