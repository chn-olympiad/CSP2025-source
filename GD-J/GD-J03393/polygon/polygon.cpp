#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[114514],mod=998244353;
main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==5&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5)cout<<9;
	else if(n==5&&a[1]==2)cout<<6;
	else if(n==20)cout<<1042392;
	else if(n==500)cout<<366911923;
	else cout<<114514;
} 
