#include<bits/stdc++.h> 
using namespace std;
struct W
{
	int a[3];
}w[100005];
bool cmp(W p,W q)
{
	if(min(p.a[0],min(p.a[1],p.a[2]))==0&&min(q.a[0],min(q.a[1],q.a[2]))!=0)return true;
	if(min(p.a[0],min(p.a[1],p.a[2]))!=0&&min(q.a[0],min(q.a[1],q.a[2]))==0)return false;
	return max(p.a[0],max(p.a[1],p.a[2]))>max(q.a[0],max(q.a[1],q.a[2]));
}
int t,n,ans,abc[3],f[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>w[i].a[0]>>w[i].a[1]>>w[i].a[2];
		sort(w+1,w+1+n,cmp);
		for(int i=1;i<=n;i++)
		{
			if(w[i].a[0]>=w[i].a[1]&&w[i].a[1]>=w[i].a[2])f[0]=0,f[1]=1,f[2]=2;
			else if(w[i].a[1]>=w[i].a[2]&&w[i].a[2]>=w[i].a[0])f[0]=1,f[1]=2,f[2]=0;
			else if(w[i].a[2]>=w[i].a[0]&&w[i].a[0]>=w[i].a[1])f[0]=2,f[1]=0,f[2]=1;
			else if(w[i].a[1]>=w[i].a[0]&&w[i].a[0]>=w[i].a[2])f[0]=1,f[1]=0,f[2]=2;
			else if(w[i].a[2]>=w[i].a[1]&&w[i].a[1]>=w[i].a[0])f[0]=2,f[1]=1,f[2]=0;
			else if(w[i].a[0]>=w[i].a[2]&&w[i].a[2]>=w[i].a[1])f[0]=0,f[1]=2,f[2]=1;
			for(int j=0;j<=2;j++)
			{
				if(abc[f[j]]<n/2)
				{
					abc[f[j]]++;
					ans+=w[i].a[f[j]];
					break;
				}
			}
		}
		cout<<ans<<endl;
		ans=0;
		memset(abc,0,sizeof abc);
	}
}

