#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200000;
int n,q;
string s1[N+5],s2[N+5];

signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	 } 
	 while(q--)
	 {
	 	int ans=0;
	 	string t1="",t2="";
	 	cin>>t1>>t2;
	 	for(int i=1;i<=n;i++)
	 	{
		 	string f=s1[i];
		 	string p="";
		 	bool bz=0;
		 	int len=0;
		 	int z=0;
	 		for(int j=0;j<t1.size();j++)
	 		{
	 			if(t1[j]==f[len])
	 			{
	 				len++;
				}
				else len=0;
				if(len==f.size())
				{
					
					bz=1;
					z=j-len;
					break;
				} 
			}
			if(bz==1) 
			{
				for(int j=0;j<=z;j++)
				{
					p=p+t1[j];
				}
				p=p+s2[i];
				for(int j=z+len+1;j<t1.size();j++) p=p+t1[j];
			}
			if(p==t2) ans++;
		 }
		 cout<<ans<<"\n";
	 }
	return 0;
}

