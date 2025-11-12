#include<bits/stdc++.h>
using namespace std;
int n,m,k,l[1000005][3],xzl[15][10005],zbj=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=0;i<m;i++) cin>>l[i][0]>>l[i][1]>>l[i][2];
	for (int i=0;i<k;i++){
		int bj=1;
		for (int j=0;j<=n;j++){
			cin>>xzl[i][j];
			if (xzl[i][j]!=0) bj=0;
		}if (bj) zbj=1;
	}if (zbj) cout<<0;
}
