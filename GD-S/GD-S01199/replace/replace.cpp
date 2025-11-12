#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[10005],s2[10005];
map<string,int> d;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1; i<=n; i++)
	{
		cin>>s1[i]>>s2[i];
		d[s1[i]]=i;
		d[s2[i]]=i;
	}
	while(q--)
	{
		int ans=0;
		string a1,a2;
		string k1="",k2="";
		int x=0,y=0;
		cin>>a1>>a2;
		int len1=a1.size(),len2=a2.size();
		for(int i=0; i<max(len1,len2); i++)
		{
			if(a1[i]!=a2[i])
			{
				if(x==0)
				{
					x=i;
					y=i;
				}
				k1+=a1[i];
				k2+=a2[i];
			}
		}
		if(k1.size()!=k2.size())
		{
			cout<<"0"<<endl;
			continue;
		}
		if(d[k1]==d[k2]&&d[k1]!=0)
		{
			ans++;
		}
		int len3=k1.size();
		string kk=k1,kkk=k2;
		for(int i=x-1; i>=0; i--)
		{
			k1+=a1[i];
			k2+=a2[i];
			if(d[k1]==d[k2]&&d[k1]!=0)
			{
				ans++;
			}
		}
		k1=kk,k2=kkk;
		string ff=k1,fff=k2;
		for(int i=x+len3; i<=max(len1,len2); i++)
		{
			k1+=a1[i];
			k2+=a2[i];
			if(d[k1]==d[k2]&&d[k1]!=0)
			{
				ans++;
			}
		}
		k1=ff,k2=fff;
		for(int i=x-1,j=x+len3; i>=0,j<=max(len1,len2); i--,j++)
		{
			k1+=a1[i];
			k1+=a1[j];
			k2+=a2[i];
			k2+=a2[j];
			if(d[k1]==d[k2]&&d[k1]!=0)
			{
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
