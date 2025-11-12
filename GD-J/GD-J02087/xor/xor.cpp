#include<bits/stdc++.h>
using namespace std;
long long n,k,a[1000005],w[1000005],xb,bx,maxx,cishu,ans;
string b[1000005],kk;
string fk(long long x)
{
	string q="";
	while(x>0)
	{
		w[++bx]=x%2;
		x=x/2;
		cishu++;
	}
	for(long long i=1,j=bx;i<j;i++,j--)
		swap(w[i],w[j]);
	for(long long i=1;i<=bx;i++)
		q+=char(w[i]+'0');
	return q;
}
string yh(string p,string q)
{
	string y="";
	for(long long i=0;i<p.size();i++)
	{
		if(p[i]!=q[i]) y+='1';
		else y+='0';
	}
	return y;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	kk=fk(k);
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		bx=cishu=0,b[++xb]=fk(a[i]);
		if(b[xb]=="") b[xb]="0";
		maxx=max(maxx,cishu);
	}
	for(long long i=1;i<=n;i++)
	{
		if(b[i].size()!=cishu)
		{
			string s="";
			for(long long j=1;j<=cishu-b[i].size();j++)
				s+='0';
			b[i]=s+b[i];
		}
	}
	for(long long i=0;i<=n;i++)
	{
		for(long long j=1;j<=n-i+1;j++)
		{
			string w=b[j];
			for(long long k=j;k<j+i;k++)
				w=yh(w,b[k]);
			if(w==kk) ans++;
		}
	}
	cout<<ans;
	return 0;
}
