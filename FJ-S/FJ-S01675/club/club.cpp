#include<cstdio>
#include<vector>
#include<algorithm>

//#include<iostream>

#define N 100010
using namespace std;
inline int read()
{ char ch=getchar();int p=0;
  for(;ch<'0'||'9'<ch;ch=getchar());
  for(;'0'<=ch&&ch<='9';p=(p<<3)+(p<<1)+ch-'0',ch=getchar());
  return p;
}
inline void print(const int &x)
{ if(x<0) { putchar('-'),print(-x); return; }
  if(x<10) { putchar(x+'0'); return; }
  print(x/10),putchar(x%10+'0');
}
int a[N][4];
vector<int> vec[4],d;
signed main()
{ freopen("club.in","r",stdin);
  freopen("club.out","w",stdout);
  int T=read();
  while(T--)
	{ int n=read();
	  for(int i=1;i<=n;i++)
		for(int j=1;j<=3;j++)
		  a[i][j]=read();
	  for(int i=1;i<=n;i++)
		if(a[i][1]>a[i][2])
		  if(a[i][1]>a[i][3]) vec[1].push_back(i);
		  else vec[3].push_back(i);
		else
		  if(a[i][2]>a[i][3]) vec[2].push_back(i);
		  else vec[3].push_back(i);
	  int ans=0;
	  for(int i=1;i<=3;i++)
		{ int up=(int)vec[i].size();
		  for(int j=0;j<up;j++) ans+=a[vec[i][j]][i];
		}
	  int fk=0;
	  for(int i=1;i<=3;i++)
		if(n/2<(int)vec[i].size())
		  { fk=i; break; }
	  
//	  cerr<<fk<<" too much "<<endl;
	  
	  if(fk)
		{ int up=(int)vec[fk].size();
		  for(int i=0;i<up;i++)
			{ int v1=0,v2=0;
			  for(int j=1;j<=3;j++)
				if(j==fk) v1=a[vec[fk][i]][j];
				else v2=max(v2,a[vec[fk][i]][j]);
			  d.push_back(v1-v2);
			}
		  
//		  cerr<<"delta:\n";
//		  for(int i=0;i<up;i++)
//			cerr<<d[i]<<' ';
//		  cerr<<endl;
		  
		  sort(d.begin(),d.end());
		  
//		  cerr<<"delta(sort):\n";
//		  for(int i=0;i<up;i++)
//			cerr<<d[i]<<' ';
//		  cerr<<endl;
		  
		  for(int i=0;i<up-n/2;i++) ans-=d[i];
		}
	  print(ans),putchar('\n');
	  for(int i=1;i<=3;i++) vec[i].clear();
	  d.clear();
	}
}
/*
1
4
0 1 0
0 1 0
0 2 0
0 2 0
*/