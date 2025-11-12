#include<bits/stdc++.h>
using namespace std;
int t,n,s[4],sum,a[100010][4],b[100010][4],mi=110000000;
void f(int x,int y)
{ 
   if((a[x][1]+a[y][2])>(a[x][2]+a[y][1]))
  { mi=min(mi,a[x][1]+a[y][2]-a[x][2]-a[y][1]);
  }
  else
  { mi=min(mi,a[x][2]+a[y][1]-a[x][1]-a[y][2]);
  }
}
int main()
{ freopen("club.in","r",stdin);
  freopen("club.out","w",stdout);
  cin>>t;
  for(int z=1;z<=t;z++)
  { cin>>n;
    sum=0;
    for(int i=1;i<=n;i++)
    { cin>>a[i][1]>>a[i][2]>>a[i][3];
      b[i][1]=1;
      b[i][2]=2;
      b[i][3]=3;
      for(int j=1;j<=3;j++)
      for(int k=2;k<=3;k++)
      { if(a[i][j]<a[i][k])
        { a[i][j]=a[i][k];
          a[i][k]=a[i][j];
          b[i][j]=b[i][k];
          b[i][k]=b[i][j];
		}
	  }
	}
	for(int i=1;i<=n;i++)
	{ if((s[b[i][1]]+1)<=(n/2))
	  { sum+=a[i][1];
	    s[b[i][1]]++;
	  }
	  else
	  { 
	    for(int j=1;j<i;j++)
	    { if((a[j][1]==a[i][1])&&(a[j][2]==a[i][2]))
	      { continue;
		  }
		  else
		  { f(j,i);
		  }
		}
		sum=mi+sum;
	  }
	}
	cout<<sum<<endl;
  }
  return 0;
 } 
