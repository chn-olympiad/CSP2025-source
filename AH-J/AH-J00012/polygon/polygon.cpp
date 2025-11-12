#include <bits/stdc++.h>
using namespace std;
int a[5010],s=0,n;
int b(int x,int cc,int mm){
	cc--;
	int ss=0;
	if(cc>0)
	{
		for(int x;x<n;x++)
		{
			mm+=a[x];
			ss+=b(x,cc,mm);
		}
	}else if(cc==0)
	{
		for(int x;x<n;x++)
		{
			if(a[x]<mm)
			{
				ss++;
			}else {
				return ss;
			}
		}
	}
	
				return ss;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long int m;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=3;i<=n;i++)
	{
		m=0;
		for(int j=0;j<n;j++)
		{
			s+=b(j,i,m);
		}
	}
	cout<<s;
	return 0;
}
