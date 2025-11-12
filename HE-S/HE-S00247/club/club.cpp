#include<bits/stdc++.h>
using namespace std;
struct number{
	int a,b,c;
}a[100011];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n=0,num=0,maxn=0;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		int m=0;
		num=0;
		cin>>m;
		for(int i=1;i<=m;++i)
		{
			cin>>a[i].a>>a[i].b>>a[i].c;
			maxn=max(a[i].a,a[i].b);
			maxn=max(a[i].c,maxn);
			num+=maxn;
		}
		
		int x=m/2;
		cout<<num<<endl;
	}
	
	return 0;
}
