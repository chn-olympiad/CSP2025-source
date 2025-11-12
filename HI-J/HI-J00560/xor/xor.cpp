#include<bits/stdc++.h>
using namespace std;

int bstoi(string r)
{
	int res=0;
	int sz=r.size();
	reverse(r.begin(),r.end());
	for(int i=0;i<sz;i++)
	{
		if(r[i]=='1')
		{
			res+=pow(2,i);
		}
	}
	return res;
}
string tob(int a)
{
	string as;
	while(a!=0)
	{
		as=as+to_string(a%2);
		a=(a-(a%2))/2;
	}
	return as;
}
int x(int a,int b)
{
	string as=tob(a);
	string bs=tob(b);
	reverse(as.begin(),as.end());
	reverse(bs.begin(),bs.end());
	while(as.size()<bs.size())
	{
		as='0'+as;
	}
	while(bs.size()<as.size())
	{
		bs='0'+bs;
	}
	
	int sz=as.size();
	string r;
	for(int i=0;i<sz;i++)
	{
		char asi=as[i];
		char bsi=bs[i];
		if(asi=='1')
		{
			if(bsi=='1')
			{
				r=r+'0';
			}
			else
			{
				r=r+'1';
			}
		}
		else
		{
			if(bsi=='1')
			{
				r=r+'1';
			}
			else
			{
				r=r+'0';
			}
		}
	}
	int jie=bstoi(r);
	
	return jie;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	vector<int>v(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	int p=0;
	int allf=-1,allb=-1;
	for(int f=0;f<n;f++)
	{
		for(int b=f;b<n;b++)
		{
			int s=v[f];
			if(f==b)
			{
				if(s==k)
				{
					p++;
				}
				continue;
			}
			for(int i=f+1;i<=b;i++)
			{
				s=x(s,v[i]);
			}
			
			if(s==k)
			{
				p++;
			}
		}
	}
	cout<<p-1;
	
	
	
	
	return 0;
}
