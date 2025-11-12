#include<bits/stdc++.h>
using namespace std;
struct qj
{
	int l,r;
}c[500005];
bool cmp(qj a,qj b)
{
	if(a.r!=b.r)return a.r<b.r;
	else return a.l<b.l;
}
long long n,k,a[500005],b[500005],x,y,rr,s;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i==1)b[i]=a[i];
		else b[i]=b[i-1]^a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(i-1>0)s=b[j]^b[i-1];
			else s=b[j];
			if(s==k)c[x].l=i,c[x++].r=j;
		}
	}
	sort(c,c+x,cmp);
	y=1;
	rr=c[0].r;
	for(int i=1;i<x;i++)
	{
		if(c[i].l>rr)y++,rr=c[i].r;
	}
	cout<<y;
	
	return 0;
}
