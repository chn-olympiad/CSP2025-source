#include<bits/stdc++.h>
using namespace std;
const int md=998244353;
int n,ans; 
int a[5005],cnt[5005];
int biter(int x){
	int ans=0;
	while(x){
		if(x%2){
			ans++;
		}
		x/=2;
	}
	return ans;
}
bool check(int x){
	if(biter(x)<3){
		return false;
	}
	int maxer=-1,sumer=0;
	for(int i=n;i>=1;i--){
		if(x&1){
			maxer=max(maxer,a[i]);
			sumer+=a[i];
		}
		x/=2;
		if(x==0){
			break;
		}
	}
	if(sumer>2*maxer){
		return true;
	}else{
		return false;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >>n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		cnt[a[i]]++;
	}
	if(n>20){
		int res=1;
		for(int i=1;i<=n;i++){
			res=res*2%md;
		}	
		int kap=1+n+n*(n-1);
		if(res<kap){
			cout << res+md-kap<<endl;
		}else{
			cout << res-kap<<endl;
		}
	}else{
		int k=pow(2,n);
		for(int i=1;i<=k;i++){
			if(check(i)){	 	
				ans++;
			}	
		}
		cout << ans;
	}	
	return 0;
} 
