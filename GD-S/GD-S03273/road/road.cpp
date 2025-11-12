#include<bits/stdc++.h>
using namespace std;
int ro[11][10001];
int xc[100];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,f;
	long long cnt = 0;
	cin>>n>>m>>k;
	for(int i = 1;i<=m;i++){
		int x,y,c;
		cin>>x>>y>>c;
		cnt+=c;
	}
	bool flag = 1;
	for(int i = 1;i<=k;i++){
		cin>>xc[i];
		if(xc[i]!=0) flag = 0;
		for(int j = 1;j<=n;j++){
			cin>>f[i][j];
			if(xc[i]!=0) flag = 0;
		}
	}
	cin>>f;
	if(f!=0) flag = 0;
	if(flag){
		printf("0");
		return 0;
	}
	else
		printf("%lld",cnt);
	return 0;
}
