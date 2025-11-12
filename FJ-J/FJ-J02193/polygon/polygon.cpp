#include<bits/stdc++.h>
using namespace std;
int l[5001];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,sum=0,tmp;
	cin>>n;
	for(int i=1;i<=n;i++)
	  cin>>l[i];
	for(int j=1;j<=n;j++)
	  for(int k=1;k<=n-j;k++)
	  {
	  	  tmp=l[k];
	  	  l[k]=l[k+1];
	  	  l[k+1]=tmp;
	  }
	for(int x=1;x<=n;x++)
	  for(int y=x+1;y<=n;y++)
	    for(int z=y+1;z<=n;z++)
	    {
	    	if(l[x]+l[y]+l[z]>2*l[n]) sum++;
		}
	cout<<sum;
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}