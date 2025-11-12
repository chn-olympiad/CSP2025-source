#include<bits/stdc++.h>
using namespace std;
const int N=1e4+7;
int n,q;
string l[N],r[N],ql[N],qr[N];
int qa[N];
int  bi(string a,string b,c)
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n;
	cin>>q;
	int a=0;
	for(int i=1;i<=n;i++)
	{
		cin>>l[i]>>r[i];
		for(int j=1;j<=n;j++)
		{
			if(l[i][j]!=r[i][j])qa[i]=j;
		}
		if(l[i]==r[i])a++;
	}
	for(int i=1;i<=q;i++)
	{
		cin>>ql[i]>>qr[i];
		if(ql[i]==qr[i])
		{
			cout<<a;
			return 0;
		}
		int Ll=ql[i].size(),Lr=qr[i].size();
		if(Ll!=Lr)
		{
			cout<<0;
			return 0;
		}
		for(int j=1;j<=Ll;j++)
		{
			if(ql[i][j]!=qr[i][j])
			{
				for(int k=1;k<=n;k++)
				{
					 if(qa[k]==ql[i][j])
					 {
					 	cout<<k;
					 	return 0;
					 }
				}
			} 
		}
	}
	
	return 0;	
} 
