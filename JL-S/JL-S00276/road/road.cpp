#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, k, u, v, w, a, b, ans, mans=INT_MAX;
int minn =INT_MAX;
int l[10003][10003], ch[11][10003], c[11], q[10003], h[10003][10003], mj[11][10003];
//int asd[10003][10003];
signed main(){
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1; i<=m; i++){
		cin >> u >> v >> w;
		l[u][v] =w;  l[v][u] =w;  h[u][v] =1;  h[v][u] =1;
		//ll[u][v] =w;  ll[v][u] =w;
		if( w <minn ){
			minn =w;
			a =u;  b =v;
		}
	}
	for(int i=1; i<=k; i++){
		for(int j=1; j<=n; j++)  mj[i][j] =INT_MAX;
	}
	for(int i=1; i<=k; i++){
		cin >> c[i];
		for(int j=1; j<=n; j++){
			cin >> w;
			mj[i][j] =w;
			//if( w<mj[i][j] ){
			//	mj[i][j] =w;
			//}
		}
	}
	if( k==0 ){
		int ok =0;
		q[a] =1;  q[b] =1;  ok +=2;  ans +=minn;
		while( ok!=n ){
			int minn =INT_MAX;
			for(int i=1; i<n; i++){
				for(int j=i+1; j<=n; j++){
					if( ( (q[i]==1 && q[j]!=1) || (q[j]==1 && q[i]!=1) ) && h[i][j]==1 ){
						if( l[i][j] <minn ){
							minn =l[i][j];
							a =i;  b =j;
						}
					}
				}
			}
			q[a] =1;  q[b] =1;  ok++;
			ans +=minn;
			//cout << ok << endl;
		}
		cout << ans << endl;
	}
	else{
		for(int o=1; o<=k; o++){
			int ok =0;  ans =0;
			for(int i=1; i<=n; i++){
				q[i] =0;
				for(int j=1; j<=n; j++)  ch[i][j] =INT_MAX;
			}
			for(int i=1; i<=n; i++){
				if( mj[o][i] ==0 ){
					//cout << i << endl;
					q[i] =1;  ok++;
					for(int j=1; j<=n; j++){
						if( j!=i ){
						//	asd[i][j] =l[i][j];
							ch[i][j] =min( l[i][j], mj[o][j] );
						}
					}
				}
			}
			while( ok!=n ){
				int minn =INT_MAX;
				for(int i=1; i<n; i++){
					for(int j=i+1; j<=n; j++){
						if( ( (q[i]==1 && q[j]!=1) || (q[j]==1 && q[i]!=1) ) && h[i][j]==1 ){
							if( min(ch[i][j],l[i][j])<minn ){
								minn =min(ch[i][j],l[i][j]);
								a =i;  b =j;
								//cout << a << endl <<b << endl;
							}
						}
					}
				}
				//cout << ch[a][b] << endl;
				q[a] =1;
				q[b] =1;
				ok++;   //cout << a<<endl << b << endl;
				ans +=ch[a][b]; // cout << minn << endl;
				//cout << ok <<endl;
			//cout << ok << endl;
			}
			//cout << ans << endl;
			mans =min( mans, ans );
		}
		cout << mans << endl;
	}
	return 0;
}
