#include<bits/stdc++.h>
using namespace std;
long long n,k,xx=INT_MAX,yy,XX,YY=INT_MAX;
long long ans;
long long a[200005],s[200005];
bool f[200005];
bool check(int x,int y){
	if((s[x] xor s[y-1])==k){
		if(x<xx) return true;
		else if(y>yy) return true;
		else {
			for(int i=y;i<=x;i++){
				if(f[i]) return false;
			} 
			return true;
		}
	}
}
void solve2(int x,int y){
	ans++;
	if(x<xx) xx=y;
	else if(y>yy) yy=x;
	else {
		for(long long i=y;i<=x;i++){
			f[i]=1;
		}
	}
} 
void solve(){
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		s[i]=(s[i-1] xor a[i]);
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=i;j++){
			if(check(i,j)) solve2(i,j);
		}
	}
	cout<<ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int T=1;
	while(T--){
		solve();
	}
	return 0;
}//#Shang4Shan3Ruo6Shui4

