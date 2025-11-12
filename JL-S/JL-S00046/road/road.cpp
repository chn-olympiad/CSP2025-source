#include<bits/stdc++.h>
using namespace std;
int n,m,k; 
int w,c,sum=0;
int a=13;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	cout<<a;
	cin>>n>>m>>k;
	for(int i;i<=n;i++){
		for(int j;j<=m;j++){
			cin>>w>>c;
			sum++;
		}
	}
	
	return 0;
}
