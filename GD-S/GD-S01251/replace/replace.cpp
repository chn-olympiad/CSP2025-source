#include<bits/stdc++.h>
using namespace std;
int n,q,b1[214514],b2[214514];
string s1[214514],s2[214514],t1,t2;
long long ans;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);	
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<s1[i].size();j++)
		{
			if(s1[i][j]=='b') b1[i]=j;
			if(s2[i][j]=='b') b2[i]=j;
		}
	}
	while(q--) 
	{
		ans=0;
		int p=0;
		cin>>t1>>t2;
		if(t1.size()!=t2.size())
		{
			printf("0\n");continue;	
		}
		for(int i=0;i<t1.size();i++)
		{
			if(t1[i]!='a'&&t1[i]!='b') p=1;
		}
		if(!p)
		{
			int bb1,bb2;
			for(int i=0;i<t1.size();i++)
			{
				if(t1[i]=='b') bb1=i;
				if(t2[i]=='b') bb2=i;
			} 
			for(int i=1;i<=n;i++)
			{
				int ss1=s1[i].size()-b1[i],ss2=t1.size()-bb1;
				if(bb2-bb1==b2[i]-b1[i]&&b1[i]<=bb1&&ss1<=ss2) ans++;	
			}
			printf("%lld\n",ans);
			continue;
		} 
		for(int i=1;i<=n;i++)
		{
			if(s1[i]==t1&&s2[i]==t2)
			{
				ans++;continue;
			}
			for(int j=0;j-1+s1[i].size()<t1.size();j++)
			{
				string nt=t1,nt1=t1,pd1=t1,pd2=t2;
				pd1.erase(j+s1[i].size(),t1.size()-j-s1[i].size());pd1.erase(0,j);
				pd2.erase(j+s1[i].size(),t1.size()-j-s1[i].size());pd2.erase(0,j);
				if(!(pd1==s1[i]&&pd2==s2[i])) continue;
				nt.erase(j,t1.size()-j);nt+=s2[i];nt1.erase(0,j+s1[i].size());
				nt+=nt1;
				if(nt==t2) ans++;
			}
		} 
		printf("%lld\n",ans);
	}
	return 0;
}
