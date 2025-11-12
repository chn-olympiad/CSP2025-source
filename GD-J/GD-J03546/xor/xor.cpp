#include<bits/stdc++.h>
using namespace std;
int n,k;
const int N = 5e5+10,M = 1e3+10;
int a[N];
int ans;
int sum[M][M];
bool vis2[N];
int g[N];
void solve1(){
	ans = n/2;
}
void solve2(){
	for(int i = 1;i<=n;i++){
		if(a[i]==k) ans++;
		else if(k==0&&i!=n&&a[i]==a[i+1]) {
			ans++;
			i++;
		}
	}
}
void solve3(){
	for(int i = 1;i<=n;i++){
		sum[i][i] = a[i];
		if(sum[i][i]==k) vis2[i] = 1;
		for(int j = i+1;j<=n;j++){
			sum[i][j] = (sum[i][j-1]^a[j]);
			if(sum[i][j]==k){
				g[i] = j;
				break;
			}
		}
	}
	for(int i = 1;i<=n;i++){
		if(vis2[i]==0){
			bool ok3 = 1;
			for(int j = i+1;j<=g[i];j++){
				if(vis2[j]){
					ok3 = 0;
					break;
				}
			}
			if(ok3){
				ans++;
				i = g[i];
			}
		}
		else{
			ans++;
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool ok = 1;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) ok = 0;
	}
	if(k==0&&ok) solve1();
	else if(k<=1) solve2();
	else if(n<=1000) solve3();
	cout<<ans;
	return 0;
}
