#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll ans,sum;
ll a[5005];
void qiuhe(int x,int y,int z,int m){
	ll cnt=0;ll maxx;
	cnt+=a[x];
	cnt+=a[y];
	maxx=max(maxx,max(a[x],a[y]));
	for(int i=z;i<=z+m;i++){
		maxx=max(maxx,a[i]);
		cnt+=a[i];
	}
	if(maxx*2>cnt){
		ans++;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	if(n<=3){
		if(sum>max(a[1],max(a[2],a[3]))*2){
			cout<<1;
			return 0;
		} 
		else{
			cout<<0;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int l=0;l<=n-3;l++){
					qiuhe(i,j,k,l);
				}
			}
		}
	}
	cout<<ans%998244353;
	return 0;
}
