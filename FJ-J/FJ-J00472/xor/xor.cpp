#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, k, a[550000], ans=0, sum=0;
//int ji;
bool fl1=true, fl2=true, fl3=true, vis[550000];
//Òì»ò : a^b;
ll xor_(int a, int b){
	ll cnt=0, i=1, x[114];
	while(a>0 || b>0){
		x[i++]=(a%2+b%2)%2;
		a/=2;
		b/=2;
	}
	for(ll j=1;j<=i;j++){
		cnt+=x[j]*(1 << (j-1));
	}
	return cnt;
}
void dfs(int t, int s){
	if(t>n)return ;
	if(s==k){
		ans++;
		return ;
	}
	dfs(t+1, xor_(s, a[t]));
	dfs(t+1, 0);
	return ;
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]!=1){
			fl1=false;
		}
		if(a[i]>1){
			fl2=false;
		}
		if(a[i]>255){
			fl3=false;
		}
	}
	if(fl1){
		cout << n/2 << '\n';
		return 0;
	}else if(fl2){
		for(int i=1;i<=n;i++){
			if(a[i]==k && !vis[i]){
				vis[i]=true;
				ans++;
//				cout << i << ' ';
				continue;
			}
			if(a[i]^a[i+1]==k && !vis[i] && !vis[i+1]){
				ans++;
//				cout << i << ' ';
				vis[i]=true;
				vis[i+1]=true;
			}
		}
//		cout << '\n';
		cout << ans << '\n';
		return 0;
	}else if(fl3){
		dfs(1, 0);
		/*for(int i=1;i<=n;i++){
//			if(sum==0)ji=i;
			if(a[i]==k && !vis[i]){
				sum=0;
				ans++;
//				cout << i << ' ';
				vis[i]=true;
				continue;
			}
			if(!vis[i]){
				sum^=a[i];
				vis[i]=true;
			}
			if(sum==k){
				ans++;
//				cout << ji << ' ';
				sum=0;
			}
		}
//		cout << '\n';*/
		cout << ans << '\n';
		return 0;
	}else{
		dfs(1, 0);
		cout << ans << '\n';
	}
	return 0;
}
