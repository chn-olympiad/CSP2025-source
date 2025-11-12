#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long n,ans,m,b1[N],w,b2[N],b3[N],t,a[N][5],top[5],mx,qwq;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		top[1]=top[2]=top[3]=ans=0;
		for(int i=1;i<=n;++i)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			mx=max(a[i][1],max(a[i][2],a[i][3]));
			if(mx==a[i][1]) ++top[1],b1[top[1]]=mx-max(a[i][2],a[i][3]);
			else if(mx==a[i][2]) ++top[2],b2[top[2]]=mx-max(a[i][1],a[i][3]);
			else if(mx==a[i][3]) ++top[3],b3[top[3]]=mx-max(a[i][1],a[i][2]);
			ans+=mx;
		}
		qwq=0;
		for(int i=1;i<=3;++i)
			if(top[i]>n/2) qwq=i;
		if(qwq)
		{
			w=0;
			if(qwq==1)
			{
				sort(b1+1,b1+top[1]+1);
				for(int i=1;i<=top[1];++i)
				{
					++w;
					ans-=b1[i];
					if(top[1]-w==n/2) break;
				}
			}
			if(qwq==2)
			{
				sort(b2+1,b2+top[2]+1);
				for(int i=1;i<=top[2];++i)
				{
					++w;
					ans-=b2[i];
					if(top[2]-w==n/2) break;
				}
			}
			if(qwq==3)
			{
				sort(b3+1,b3+top[3]+1);
				for(int i=1;i<=top[3];++i)
				{
					++w;
					ans-=b3[i];
					if(top[3]-w==n/2) break;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
 } 
