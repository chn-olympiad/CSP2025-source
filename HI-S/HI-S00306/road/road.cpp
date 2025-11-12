#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
long long f[10010],a[10010][10010],b[10010],c[10005][10005],c1[10005],d,ans;
long long f2(){
	int minn = 1e9;
	int z = 1;
	for(int i = 1;i <= n;i++){
		if(b[i] == 1) continue;
		if(f[i] <= minn){
			z = i;
			minn = f[i];
		}
	}
	return z;
}
long long f1(int x,int y){
	long long minn = 1e9;
	for(int i = 1;i <= k;i++){
		minn = min(minn,c[i][x]+c[i][y]+c1[i]);
	}
	return minn;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	d = n;
	//memset(a,sizeof(a),1e9);
	//memset(f,sizeof(f),1e9);
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			a[i][j] = 1e9;
		}
	}
	for(int i = 1;i <= n;i++){
		f[i] = 1e9;
	}
	f[1] = 0;
	for(int i = 1;i <= m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		a[u][v] = w;
		a[v][u] = w;
	}
	for(int i = 1;i <= k;i++){
		cin >> c1[i];
		for(int j = 1;j <= n;j++){
			cin >> c[i][j];
		}
	}
	//cout << endl;
	//for(int i = 1;i <= n;i++){
	//	for(int j = 1;j <= n;j++){
	//		cout << a[i][j] << " ";
	//	}
	//}
	//cout << endl;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(i == j) continue;
			a[i][j] = min(a[i][j],f1(i,j));
			//cout << a[i][j] << endl;
		}
	}
	while(d > 0){
		int i = f2();
		d--;
		b[i] = 1;
		//cout << i << " ";
		for(int j = 1;j <= n;j++){
			if(b[j] == 1) continue;
			f[j] = min(f[j],a[i][j]); 
		}
		//cout << endl;
	}
	//for(int i = 1;i <= n;i++){
	//	for(int j = 1;j <= n;j++){
	//		cout << a[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	for(int i = 1;i <= n;i++){
	//	cout << f[i] << " ";
		ans += f[i];
	}
	//cout << endl;
	cout << ans;
	return 0;
}

