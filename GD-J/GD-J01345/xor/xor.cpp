#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,s[N],c,f[N];
struct qj
{
	int l,r;
}p[N];
inline int get(int l,int r)
{
	if(l>1)
		return s[r]^s[l-1];
	if(l==1)
		return s[r];
}
bool cmp(qj a,qj b)
{
	if(a.l==b.l)
		return a.r<b.r;
	return a.l<b.l;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1,t;i<=n;i++)
	{ 
		cin>>t;
		if(i>1)s[i]=s[i-1]^t; 
		else s[i]=t;
		for(int j=1;j<=i;j++)
		{
			if(get(j,i)==k)
			{
				c++;
				p[c].l=j,p[c].r=i;
			} 
		}
	}
	sort(p+1,p+1+c,cmp);
	for(int i=1;i<=c;i++)
	{
		f[i]=1;
		for(int j=1;j<i;j++)
		{
			if(p[j].r<p[i].l)
				f[i]=max(f[i],f[j]+1); 
		}
	}
	cout<<f[c]; 
	return 0;
} 
