#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,sum;
	sum=1;
	cin>>n>>m>>k;
	int i[100000][3];
	int j[100]; 
	for(int q=0;q<m+k;q++)
	{
		cin>>i[q][0]>>i[q][1]>>i[q][2];
		sum+=i[q][0];
	}
	cout<<sum;
	return 0;
 }
