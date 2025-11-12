#include<bits/stdc++.h>
using namespace std;
int n,q,n1,n2,m,l,r,L,R;
char a[1005][2005],b[1005][2005],x[2005],y[2005];
int checkx(char s[2005])
{
	int d=strlen(s);
	if(d!=r-l+1) return 0;
	for(int i=0;i<d;i++)
	{
		if(s[i]!=x[i+l]) return 0;
	}
	return 1;
}
int checky(char s[2005])
{
	int d=strlen(s);
	if(d!=r-l+1) return 0;
	for(int i=0;i<d;i++)
	{
		if(s[i]!=y[i+l]) return 0;
	}
	return 1;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	while(q--)
	{
		cin>>x>>y;
		int k=0;
		n1=strlen(x),n2=strlen(y);
		if(n1!=n2)
		{
			cout<<"0\n";
			continue;
		}
		m=n1;
		L=0,R=m-1;
		for(int i=0;i<m;i++)
		{
			if(x[i]!=y[i]) break;
			L++;
		}
		for(int i=m-1;i>=0;i--)
		{
			if(x[i]!=y[i]) break;
			R--;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			l=0;r=strlen(a[i])-1;
			while(r<m)
			{
				if(l<=L&&r>=R&&checkx(a[i])&&checky(b[i])) ans++;
				l++,r++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
