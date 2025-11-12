#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=5e5+50;
int n,m,k;
int a[N];
void solve(){
	int ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			ans++;a[i]=-1;
		}
	}
	int s;
	for(int i=1;i<=n;i++){
		s=a[i];
		for(int j=i+1;j<=n;j++){
			if(i==j||a[i]==-1||a[j]==-1) break;
			s^=a[j];
			if(s==k){
				s=a[j+1];ans++;
			}	
		}
		if(s==k){
			ans++;
		}
		
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}
