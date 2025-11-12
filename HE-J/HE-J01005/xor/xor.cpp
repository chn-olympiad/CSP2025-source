#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N];
bool check(char sp){
	int L=0,R;
	if(sp=='A') L=1,R=1;
	else if(sp=='B') R=1;
	else if(sp=='C') R=255; 
	for(int i=1;i<=n;i++){
		if(a[i]<L||a[i]>R) return false;
	}
	return true;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=2&&k==0&&check('A')) {
		if(n==1){
			cout<<0;
			return 0;
		}
		else if(n==2){
			cout<<1;
			return 0;
		}
	}
	else if(n<=100&&k==0&&check('A')) {
		cout<<n/2;
		return 0;
	}
	else if(n<=2e5&&k<=1&&check('B')) {
		if(k==0){
			int ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					if(a[i+1]==1){
						i++;ans++;
					}
				}
				else ans++;
			}
			cout<<ans;
		}
		else if(k==1){
			int ans=0;
			for(int i=1;i<=n;i++) if(a[i]==1) ans++;
			cout<<ans;
		}
	}
	return 0;
}

