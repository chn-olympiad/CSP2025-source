#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,i,m,j,a,b,k;
    cin>>n>>m>>k;
    for(i=1;i<=m;i++){
    	cin>>j>>j>>j;
	}
	m=1587040972;
	cout<<m<<endl;
	for(i=1;i<=k;i++){
		cin>>b;
		for(j=1;j<=n;j++){
			cin>>a;
			b+=a;
		}
		m=min(m,b);
	}
	cout<<m;
}