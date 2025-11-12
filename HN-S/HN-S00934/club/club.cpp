#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
int T;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	//int t1,t2,t3;
	while(T--)
	{
		cin>>n;
		int a[N],b[N],c[N];
		int s=0;
		bool b1=1;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]!=0||c[i]!=0) b1=0;
		}
		if(b1) 
		{
			sort(b+1,b+n+1);
			for(int i=1;i<=n/2;i++)
			{
				s+=b[i];
			}
		}
		else if(n==2)
		{
			s=max(a[1]+b[2],max(a[1]+c[2],max(b[1]+a[2],max(b[1]+c[2],max(c[1]+b[2],c[1]+a[2])))));
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				s+=max(a[i],max(b[i],c[i]));
			}
		}
		cout<<s;
	return 0;
}//goodbye-oi
