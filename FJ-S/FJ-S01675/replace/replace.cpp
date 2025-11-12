#include<iostream>
#include<string>
#define N 200010
using namespace std;
string s[N][3];
signed main()
{ freopen("replace.in","r",stdin);
  freopen("replace.out","w",stdout);
  ios::sync_with_stdio(false);
  int n,q;
  cin>>n>>q;
  for(int i=1;i<=n;i++) cin>>s[i][1]>>s[i][2];
  while(q--)
	{ string t1,t2;
	  cin>>t1>>t2;
	  int len1=(int)t1.size(),len2=(int)t2.size();
	  if(len1!=len2)
		{ cout<<0<<endl;
		  continue;
		}
	  t1=' '+t1,t2=' '+t2;
	  int ans=0;
	  for(int p0=1;p0<=len1;p0++)
		for(int p1=p0;p1<=len1;p1++)
		  { string x="",y="",z="";
			for(int i=1;i<p0;i++)
			  x+=t1[i];
			for(int i=p0;i<=p1;i++)
			  y+=t1[i];
			for(int i=p1+1;i<=len1;i++)
			  z+=t1[i];
			string xx="",yy="",zz="";
			for(int i=1;i<p0;i++)
			  xx+=t2[i];
			for(int i=p0;i<=p1;i++)
			  yy+=t2[i];
			for(int i=p1+1;i<=len1;i++)
			  zz+=t2[i];
			if(x==xx&&z==zz)
			  { for(int i=1;i<=n;i++)
				  if(s[i][1]==y)
					ans+=s[i][2]==yy;
			  }
		  }
	  cout<<ans<<endl;
	}
}