#include<bits/stdc++.h>
using namespace std;
int n,m,a[505],vis[505];
long long ans=1;
string s;
void d(int x,int y,int z){
	if(x>=m&&z==n){
		ans++;
		ans=ans%998244353;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==1) continue;
		if(s[z]=='1'){
			if(y>=a[i]){
				vis[i]=1;
				d(x,y+1,z+1);
				vis[i]=0;
			}else if(y<a[i]){
				vis[i]=1;
				d(x+1,y,z+1);
				vis[i]=0;
			}
		}else{
			vis[i]=1;
			d(x,y+1,z+1);
			vis[i]=0;
		}
	}
}
void solve1(){
	ans=0;
	d(0,0,0);
	cout<<ans%998244353;
}void solve3(){
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			cout<<0;
			return;
		}
		ans=(ans*i)%998244353;
	}
	cout<<ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n) solve3();
	else solve1();
	return 0;
	fclose(stdin);
	fclose(stdout);
}
