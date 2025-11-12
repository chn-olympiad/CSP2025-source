#include<bits/stdc++.h>
using namespace std;
int main(){//T4 2025/11/01 11:35:37 [0,12]pts.
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	
	int n,a[4];
	cin>>n>>a[1]>>a[2]>>a[3];
	
	bool ans=(a[1]+a[2]+a[3])>2*max(a[1],max(a[2],a[3]));
	cout<<ans;
	return 0;
}
//Overall=100+100+[5,10]+[0,12]=[205,222]pts.
//I think I can get a 1= or 2=.
//luogu:guhaoyu_1. guan zhu xie xie.
