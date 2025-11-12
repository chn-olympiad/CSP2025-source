#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],ans=0;
bool hemu(int x,int y){
	int zza=a[x];
	for(int i=x+1;i<=y;i++){
		zza=(zza^a[i]);
	}
	if(zza==k)return true;
	else return false; 
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(hemu(i,j))ans++;
		}
	}
	cout<<ans;
	return 0;
}
