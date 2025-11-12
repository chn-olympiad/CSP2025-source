#include <bits/stdc++.h>
using namespace std;
const int MAXM=1e4+2;
const int MAXN=1e6+6;
int u[MAXN],v[MAXN],w[MAXN];
int a[11][MAXM];
int usg[11];
int f[MAXM];
int n,m,k,ind=0;
int fdmin(int nc){
	int p,mins=INT_MAX;
	for(int i=1;i<=k;i++){
		p=0;
		for(int j=1;j<=n;j++){
			if(j==nc)continue;
			if(!usg[i])p=a[i][0];
			if(a[i][j]+a[i][nc]+p<mins){
				mins=a[i][j]+p;
				ind=i;
			}
		}
	}
	usg[ind]++;
	return mins;
}
int fcmin(int nc){
	int mins=INT_MAX;
	for(int i=1;i<=m;i++){
		if(u[i]==nc||v[i]==nc){
			if(w[i]<mins){
				mins=w[i];
			}
		}
	}
	return mins;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	memset(usg,0,sizeof(usg));
	for(int i=1;i<=m;i++){
		cin >> u[i] >> v[i] >> w[i];
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin >> a[i][j];
		}
	}
	f[1]=0;
	for(int i=2;i<=n;i++){
		ind=0;
		int fc=fcmin(i),fd=fdmin(i);
		if(fc<fd){
			usg[ind]--;
			f[i]=f[i-1]+fc;
		}
		else f[i]=f[i-1]+fd;
	}
	cout << f[n];
	return 0;
}
