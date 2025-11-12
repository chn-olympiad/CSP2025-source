#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,cj[101],nob=1; 
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
 	{
 		cin>>cj[i];
	} 
	for(int i=2;i<=n*m;i++)
	{
		if(cj[i]>cj[1]) nob+=1;
	}
	if(nob/n==0) cout<<nob/n<<" "<<m;
	else cout<<nob/n+1<<" "<<nob%n;
	return 0;
} 
