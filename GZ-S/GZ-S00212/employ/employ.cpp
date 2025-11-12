//GZ-S00212 贵阳市南明区华麟学校 李俊熠 
#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int n,m,a[N],d[N],m1=1;
char b[N];
int main()
{
	cin>>n>>m;
	cin>>(a+1);
	for(int i=1;i<=n;i++) 
	{
		d[i]=d[i-1]+(a[i]-'0');
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(m1==1) m1=a[i];
	}
	if(mi==1) 
	{
		
	}
	return 0;
}
