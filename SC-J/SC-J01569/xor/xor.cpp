#include <bits/stdc++.h>
using namespace std;
const int M = 100000;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[M],m[M][M],ans = 0;
	cin>>n>>k;
	for(int i = 0;i < M;i++) a[i] = -1;
	for(int i = 1;i <= n;i++) {
		cin>>a[i];
		m[i][i] = a[i];
	}
	for(int i = 1;i <= n;i++){
		for(int j = i+1;j <=n;j++){
			int x[M],y[M],xl = 0,yl = 0;
			for(int s = 0;s < M;s++){
				x[s] = 0;
				y[s] = 0;
			}
			for(int s = m[i][j];s > 0;s/2){
				x[xl] = s%2;
				xl++;
			}
			for(int s = m[i][j-1];s > 0;s/2){
				y[yl] = s%2;
				yl++;
			}
			for(int s = max(xl,yl);s >= 0;s++){
				if(x[s] != y[s]) m[i][j] += m[i][j]*2+1;
				else if(x[s] == y[s]) m[i][j] += m[i][j]*2;
			}
		}
	}
	
	for(int i = 1;i<=n;i++){
		for(int j = i;j<=n;j++){
			if(m[i][j] == k){
				ans++;
				i = j;
				j = n+1;
			}
		}
	}
	cout<<ans;
	
	return 0;
}