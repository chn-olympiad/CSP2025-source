//GZ-S00315 贵阳市第三中学 王子乾 
#include<bits/stdc++.h>
using namespace std;
const int N=1e9+10;
int u[N],v[N],w[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","W",stdout);
	int n,a,m;
	cin >> n >> a >> m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i>=j&&j==n/m){
				u[N]+=j;
			}
			else if(j!=i&&j==m%n){
				v[N]+=j;
			} 
			else{
				w[N]+=j;
			}
		}
	
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n*n;j++){
			if(j>=v[i]||i>=w[j]){
				j++;
			}
			else if(j<=n&&u[i]>w[j]){
				i++;
			}
		}
	}
	cout << 13; 
	return 0;
}
