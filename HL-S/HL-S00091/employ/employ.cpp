#include<bits/stdc++.h>
using namespace std;
int a[510];
int main(){
freopen("employ.in","r",stdin);
freopen("employ.out","w",stdout);
int n,m;
cin>>n>>m;
string t;
cin>>t;
for(int i=1;i<=n;i++)
{
	cin>>a[i];
}
int z;
for(int i=0;i<=t.length();i++)
{
	if(t[i]=='0')
	{
	z=i;
	break;
	}
}
int h=1;
if(z<=m){
for(int i=0;i<z;i++)
{
		h=h*(n-i);
}
}
else if(z>=m)
{
	for(int i=0;i<m;i++)
{

		h=h*(n-i);
	
}
}
cout<<h;
return 0;
}
//time is golden
