#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
long long a[5005],n,cnt,ma;
void dfs(int x,int y,int z){
	z+=a[y];
	if(z>x)cnt++;
	for(int i=y-1;i>=1;i--){
		dfs(x,i,z);
	}
}
int main(){
	freopen("polygan.in","r",stdin);
	freopen("polygan.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=3;i--){
		for(int j=i-1;j>=2;j--){
			dfs(a[i],j,0);
		}
	}
	cout<<cnt%Mod;
	return 0;
}
