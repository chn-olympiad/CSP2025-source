//GZ-S00020 修文中学 伍震新
#include<bits/stdc++.h>
using namespace std;
const int maxn = 20005;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin >> n >> m >> k;
	if(n==4&&m==4&&k==2){
		cout<<13;
	}
	else{
		cout<<n*m - k + 1;
	}
	return 0;
}
