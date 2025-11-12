#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
int a,s,dd=0;
cin>>a>>s;
for(int i=0;i<a;i++)
{
	cin>>s>>s>>s;
}
for(int i=0;i<a+1;i++)
{
	cin>>s;
	dd=dd+s;
}
cout<<dd;
return 0;
}
