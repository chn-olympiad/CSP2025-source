#include <iostream>
#include <algorithm>
using namespace std;
int b[5005];
int a;
int deepfind(int need,int maxx,int now,int p,int sum)
{
	int f=0;
	if(need>0)
		for(int i = p; i <= a; i++)
			f+=deepfind(need-1,max(b[i],now),b[i],i+1,sum+b[i]);
	if(need==0)
		if(sum>2*maxx)
			f++;
	return f;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	cin >> a;
	if(a==3)
	{
		int b,c,d;
		cin>>b>>c>>d;
		if(b+c>d && b+d>c && c+d>b)
			cout<<1;
		else 
			cout<<0;
	}
	else 
	{
		for(int i = 1; i <= a; i++)
			cin>>b[i];
		int ans=0;
		for(int i = 3; i <= a; i++)
			ans+=deepfind(i,0,0,1,0);
		cout<<ans%998244353;
	}
	return 0; 
}
