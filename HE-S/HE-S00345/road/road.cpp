#include <bits/stdc++.h>
using namespace std;

struct Road{
	int c1, c2, m;
}r[1000005];
struct va{
	int c, a[1005];
}v[15];

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin.tie(NULL);
	
	int n, m, k, ans=0;
	cin>>n>>m>>k;
	for(int i = 0;i<m;i++) 
		cin>>r[i].c1>>r[i].c2>>r[i].m;
	cout<<m*2+n+1<<'\n';
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
