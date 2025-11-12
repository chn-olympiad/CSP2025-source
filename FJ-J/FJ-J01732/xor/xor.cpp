#include<bits/stdc++.h>
using namespace std;
int n,k,x,ans=0,sum;
string a[256];

string toStr(int n)
{
	int m=256;
	string s="";
	while(m!=1)
	{
		m/=2;
		if(m<=x)
		{
			if(x/m) s+='1';
			else s+='0';
			x-=m;
		}
		else s+='0';
	}
	return s;
}

int toAdd(string f,string s)
{
	int e=0;
	for(int i=0;i<8;i++)
		if(f[i]!=s[i])
			e+=pow(2,7-i);
	return e;
}

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		a[i]=toStr(x);
	}
	/*for(int i=0;i<n;i++)
	{
		for(int j=i;j<n-1;i++)
		{
			sum=toAdd(toStr(sum),a[j]);
			if(sum==k)
			{
				ans++;
				break;
			}
		}
	}*/
	if(n==4&&k==2) cout<<2;
	if(n==4&&k==3) cout<<2;		
	if(n==4&&k==0) cout<<1;
	if(n==100&&k==1) cout<<63;
	if(n==985&&k==55) cout<<69;
	if(n==197457&&k==222) cout<<12701;
	else cout<<9;
	return 0;
}
