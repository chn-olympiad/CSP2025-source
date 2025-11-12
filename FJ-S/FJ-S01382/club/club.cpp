#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct Node
{
	int name,x;
}a[N],b[N],c[N];
int T,n,sum,cnt1,cnt2,cnt3;
bool st[N];
bool cmp(Node a,Node b)
{
	if(a.x>b.x)
		return true;
	return false;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","r",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n;
		sum=0;
		cnt1=0;
		cnt2=0;
		cnt3=0;
		memset(st,false,sizeof(st));
		for(int i=1;i<=n;++i)
		{
			cin>>a[i].x>>b[i].x>>c[i].x;
			a[i].name=i;
			b[i].name=i;
			c[i].name=i;
		}
		sort(a+1,a+1+n,cmp);	
		sort(b+1,b+1+n,cmp);
		sort(c+1,c+1+n,cmp);
		for(int i=1;i<=n;++i)
		{
			if(!st[a[i].name]&&cnt1<n/2&&cnt1+cnt2+cnt3<n)
				sum+=a[i].x,st[a[i].name]=true,cnt1++;
			if(!st[b[i].name]&&cnt2<n/2&&cnt1+cnt2+cnt3<n)
				sum+=b[i].x,st[b[i].name]=true,cnt2++;	
			if(!st[c[i].name]&&cnt3<n/2&&cnt1+cnt2+cnt3<n)	
				sum+=c[i].x,st[c[i].name]=true,cnt3++;
		}
		cout<<sum<<endl;
	}
	return 0;
} 
