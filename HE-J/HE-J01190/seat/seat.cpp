#include <bits/stdc++.h>
#include <string>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;int j=0;
	cin>>n>>m;
	int a[n*m+5];
	for(int i=1;i<=n*m;i++)
	cin>>a[i];
	for(int i=2;i<=n*m;i++)
	if(a[1]<a[i])j++;
	j+=1;
	if(j%n==0)cout<<j/n<<" ";
	else cout<<j/n+1<<" ";
	if(j%(2*n)==0)cout<<1;
	else if(j%(2*n)<=n)cout<<j%(2*n);
	else cout<<2*n-j%(2*n)+1;
	
	
	fclose(stdin);
	fclose(stdout);
	  return 0;
}
