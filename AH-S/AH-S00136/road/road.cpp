#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,a,b,c,sum=0;
	cin >>n>>m>>k;
	for (int i=1;i<=n;i++){
		cin >>a>>b>>c;
		sum+=c;
	}
	if (n>m)	cout <<sum<<endl;
	if (n==m)	cout <<sum-c<<endl;
	if (n<m)	cout <<sum-c*2<<endl;
	
	return 0;
}
