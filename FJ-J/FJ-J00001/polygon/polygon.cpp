#include<bits/stdc++.h>
using namespace std;
int n;
int a[4];
int ans;
int cmp(int a,int b){
	return a>b;
}
int main()
{
	ios::sync_with_stdio(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	cin>>a[1]>>a[2]>>a[3];
	sort(a+1,a+n+1,cmp);
	if((a[1]+a[2]+a[3])>(a[1]*2)) cout<<1;
	else cout<<0;
	//_-]
	return 0;
}

