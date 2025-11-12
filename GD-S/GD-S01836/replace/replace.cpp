#include<bits/stdc++.h>
using namespace std;
int n,q;
string t1,t2;
string s1,s2;
int len[200005],b1[200005],b2[200005];
string ss1[105],ss2[105];
int lenn[105];
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	if(n<=100)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>ss1[i]>>ss2[i];
			lenn[i]=ss1[i].size()-1;
		}
		while(q--)
		{
			cin>>t1>>t2;
			int ans=0;
			int len1=t1.size()-1;
			string t3=t1;
			for(int k=1;k<=n;k++)
			{
				for(int i=0;i<=len1;i++)
				{
					bool bzz=0;
					for(int j=0;j<=lenn[k];j++)
					{
						if(ss1[k][j]!=t1[i+j])
						{
							bzz=1;
							break;
						}
					}
					if(bzz==0)
					{
						for(int j=0;j<=lenn[k];j++) t3[i+j]=ss2[k][j];
						if(t3==t2) ans++;
						t3=t1;
					}
				}				
			}
			printf("%d\n",ans);
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			cin>>s1>>s2;
			s1=" "+s1,s2=" "+s2;
			len[i]=s1.size()-1;
			for(int j=1;j<=n;j++)
			{
				if(s1[j]=='b') b1[i]=j;
				if(s2[j]=='b') b2[i]=j;
			}
		}
		while(q--){
			cin>>t1>>t2;
			t1=" "+t1,t2=" "+t2;
			int t1b=0,t2b=0,len1=t1.size()-1;
			for(int i=1;i<=len1;i++)
			{
				if(t1[i]=='b') t1b=i;
				if(t2[i]=='b') t2b=i;
			}
			int ans=0;
			for(int i=1;i<=n;i++) if(len1-t1b>=len[i]-b1[i]&&t2b-t1b==b2[i]-b1[i]) ans++;
			printf("%d\n",ans);
		}		
	}


}
