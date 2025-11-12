#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll n,m,ans;
string b,_b,a[100000],c[100000],__b;
string read()
{
	string a;char b=getchar();
	for(;b>'z'||b<'a';b=getchar());
	for(;b>='a'&&b<='z';a=a+b,b=getchar());
	return a;
}
int main()
{
	freopen("replace.in","r",stdin);freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) a[i]=read(),c[i]=read();
	for(int i=1;i<=m;i++)
	{
		ans=0;
		b=read();_b=read();
		if(b.size()!=_b.size())
		{
			cout<<"0"<<endl;
		}
		else{
		for(int i=1;i<=n;i++)
		{
			__b=b;
			ll j=-1,k=0,s=0,l=__b.size(),l1=a[i].size();
			while(j<=l)
			{
				__b=b;
				j++;
				if(__b[j]==a[i][k]) 
				{
					if(k==0) s=j,k++;
					else k++;
					if(k==l1-1)
					{
						for(int q=s;q<=s+k;q++)
						{
							__b[q]=c[i][q-s];
						}
						if(__b==_b) 
						{
							ans++;
							break;
						}
						k=0;
					}
				}
				else k=0;
			}
		}
		cout<<ans<<endl;}
	}
	return 0;
}