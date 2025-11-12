#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N],b[N][51];
int n,k;
int ans=0;
void to1(int x){
	int c=a[x];
	int i=1;
	while(c){
		b[x][i]=c%2;
		c/=2;
		i++;
	}
	return;
}
int ec(int x,int y){
	int cnt=0;
	int q=1;
	for(int i=1;i<=50;i++){
		if((b[y][i]-b[x-1][i])%2) cnt+=q;
		q*=2;
	}
	return cnt;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) to1(i);
	for(int i=1;i<=n;i++) for(int j=1;j<=50;j++) b[i][j]+=b[i-1][j];
	int l=1;
	for(int i=1;i<=n;i++){
		for(int j=i;j>=l;j--){
			if(ec(j,i)==k){
				ans++;
				l=i+1;
			}
		}
	}
	cout<<ans;
	return 0;
}
