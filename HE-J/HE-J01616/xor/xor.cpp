#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=6e5+100;
int n,k;
int a[N];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	int ans=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0) ans++;
			if(a[i]==a[i+1]&&a[i]==1){
//				cout<<i<<" ";
				i++;
				ans++;
			}
		}
	}
	if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1) ans++;
		}
	}
	cout<<ans;
//	cout<<(1^2)
	return 0;
}
/*
4 1
0 0 0 0
*/
