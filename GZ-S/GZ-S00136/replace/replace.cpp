//GZ-S00136 遵义市第四中学 安睿峰 
#include <bits/stdc++.h>
using namespace std;
int n,q,num,p,c,ans;
string s1[200010],s2[200010],t1,t2,s,t;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)  cin>>s1[i]>>s2[i];
	while(q--)
	{
		s="";t="";num=0;p=0;c=0;ans=0;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){cout<<0<<endl;continue;}
		for(int i=0;i<t1.size();i++)
		{
			if(t1[i]!=t2[i])
			{
				s+=t1[i];t+=t2[i];
				num++;
				if(p==0)  p=1,c++;
			}
			else  if(p==1)  p=0;
		}
		if(c==2){cout<<0<<endl;continue;}
		for(int i=1;i<=n;i++)
		{
			if(t1.find(s1[i])>=t1.size()||s1[i].find(s)>=t1.size())  continue;
			if(t1.find(s1[i])!=t2.find(s2[i])||s1[i].find(s)!=s2[i].find(t))  continue;
			ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
