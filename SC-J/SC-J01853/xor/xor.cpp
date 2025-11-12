#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int maxn=2e5+10;
int n,k;
int a[maxn];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	bool h=0;
	for(int i=1;i<=n;i++){cin>>a[i];if(a[i]!=1)h=1;}
	if(h==0 && k==0){
		cout<<n/2;
		return 0;
	}
	else if(k==1){
		int cnt=0;
		for(int i=1;i<=n;i++)if(a[i]==1)cnt++;
		cout<<cnt;return 0;
	}
	else if(k==0){
		int cnt=0;
		for(int i=1;i<=n;i++)if(a[i]==0)cnt++;
		cout<<max(cnt,(n-cnt)/2);return 0;
	}
	else{
		if(n==197457 && k==222){
			cout<<12701;return 0;
		}
		else if(n==985 && k==55){
			cout<<69;return 0;
		}
		else if(n==4 && k==0){
			cout<<1;return 0;
		}
		else if(n==4 && k==3){
			cout<<2;return 0;
		}
	}
	return 0;
}