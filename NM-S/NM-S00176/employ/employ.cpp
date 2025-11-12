#include<bits/stdc++.h>
using namespace std;
int n,t,w[100005][5],a[4];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int z=1; z<=t; z++) {
		cin>>n;
		for(int i=1; i<=n; i++)
			cin>>w[i][1]>>w[i][2]>>w[i][3];
	}
	return 0;
}
