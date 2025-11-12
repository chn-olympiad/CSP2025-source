#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	long long n,m,k;
	cin>>n>>m>>k;
	long long N=n+m,s=(N-1)*N/2-k;
	for(int l=0;l<=m*3;l++)cin>>k;
	cout<<s*k;
	return 0;}
