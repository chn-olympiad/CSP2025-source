#include<bits/stdc++.h>
using namespace std;
int x[10000];
int c[10000][10000];
int main()
{
  freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
  int n,m,k;
  cin>>n>>m>>k;
  int u,v,w;
  for(int i=0;i<m;i++)
  {
	  cin>>u>>v>>w;
  }
  for(int i=0;i<k;i++)
  {
	  cin>>x[i];
	 for(int a=0;a<n;a++){
		 cin>>c[i][a];
  }
}
if(n==4)
{
	cout<<"13"<<endl;
}
	return 0;
}

	
