#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int N=1e5+10;

int T;
int n;
int x,y,z;
int a[N],b[N],c[N];
int cnta,cntb,cntc;
ll sum;

void cutoff(int l[],int len)
{
	sort(l+1,l+1+len);
	for(int i=1;i<=len-n/2;i++) sum-=l[i];
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>T;
	while(T--)
	{
		cnta=cntb=cntc=sum=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>x>>y>>z;
			if(x>=y&&x>=z)
			{
				sum+=x;
				a[++cnta]=min(x-y,x-z);
			}
			else if(y>=z)
			{
				sum+=y;
				b[++cntb]=min(y-x,y-z);
			}
			else
			{
				sum+=z;
				c[++cntc]=min(z-x,z-y);
			}
		}
		if(cnta+cnta>n) cutoff(a,cnta);
		if(cntb+cntb>n) cutoff(b,cntb);
		if(cntc+cntc>n) cutoff(c,cntc);
		cout<<sum<<'\n';
	}
	
	return 0;
}
