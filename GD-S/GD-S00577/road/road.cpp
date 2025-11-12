#include<bits/stdc++.h>
using namespace std;
int n,m,k,r[1000005][5],v[1000005],c = 0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	vector <int> c[1000005];
	cin >> n >> m >> k;
	for( int i = 1;i <= m;i++ ){
		int t1,t2,t3;
		c[t1].push_back(t2);
		c[t2].push_back(t1);
		r[i][1] = t1,r[i][2] = t2,r[i][3] = t3;
		if( i % t1 == 2 ) c += t3;
	}
	cout << c;
	return 0;
}
