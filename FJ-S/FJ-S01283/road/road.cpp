#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[1000005],b[1000005],c[1000005],kcost[20],l[20][1000002],sum;
int main()
{ freopen("road.in","r",stdin);
  freopen("road.out","w",stdout); 
  cin>>n>>m>>k;
  for(int i=1;i<=n;i++)
  { cin>>a[i]>>b[i]>>c[i];
  }
  for(int j=1;j<=k;j++)
  { cin>>k[j];
    for(int i=1;i<=n;i++)
    { cin>>l[j][i];
	}
  }
  cout<<sum<<endl;
  }  
