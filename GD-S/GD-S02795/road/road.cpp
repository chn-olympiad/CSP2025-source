#include<bits/stdc++.h>
using namespace std;
long long n,m,k,s;
int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		long long x,y,z;
		cin>>x>>y>>z;
		s+=z;
	}
	cout<<s;
	return 0;
}

