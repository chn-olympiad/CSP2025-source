#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read()
  {int w=0,f=1;
  char ch=getchar();
  for(;ch<'0'||ch>'9';ch=getchar())  if(ch=='-')  f=-1;
  for(;ch>='0'&&ch<='9';ch=getchar())  w=(w<<3)+(w<<1)+(ch^48);
  return w*f;
  }
const int N=2e5+10;
int n,q;
string s[N][2];
int main()
{
freopen("repalce.in","r",stdin);
freopen("replace.out","w",stdout);
cin>>n>>q;
for(int i=1;i<=n;i++)  cin>>s[i][0]>>s[i][1];
for(int i=1;i<=q;i++)
  {string t1,t2,zj;
  cin>>t1>>t2;
  if(t1.size()!=t2.size())  
    {cout<<0<<"\n";
	continue;
	}
  int ans=0;
  for(int j=1;j<=n;j++)
    {int pos=0;
    while(pos<t1.size()&&t1.find(s[j][0],pos)!=string::npos)
      {zj=t1;
	  int x=t1.find(s[j][0],pos);
	  zj.replace(x,s[j][0].size(),s[j][1]);
//	  cout<<zj<<"\n";
	  if(zj==t2)  ans++;
	  pos=x+1;
	  }
	}
//  printf("%d\n",ans);
  cout<<ans<<"\n";
  }
}


