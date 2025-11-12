#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int a,b,c,q,n;
	cin>>n;
	cin>>a>>b>>c;
	for(int i=1;i<=n-3;i++)cin>>q;
	if(a+b>c&&a-b<c&&b+c>a&&b-c<a&&a+c>b&&a-c<b)cout<<1;	
	else cout<<0;
	return 0;
}//sudiesbgunfjfbuwiwdndwnfuif64141231
