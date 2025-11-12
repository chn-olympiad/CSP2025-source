//GZ-S00092 中央民族大学附属中学贵阳学校 吴玅君
#include<bits/stdc++.h>
using namespace std;
//foruopen<"employ.in",stdin>;
//foruopen<"employ.out",stdout>;
int main(){
	int m,n,k;
	cin>>n>>m>>k;
	int a[100005][5],b[1000005][1000005];
	for(ll i=1;i<=m;i++){
		for(ll j=1;j<=3;j++){
			cin>>a[i][j];
		}
	}
	for(ll i=1;i<=k;i++){
		for(ll j=1;j<=n+1;j++){
			cin>>b[i][j];
		}
	}
	cout<<n+m+k<<endl;
	return 0;
}


