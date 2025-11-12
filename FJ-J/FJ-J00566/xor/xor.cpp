#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,a[N],ans;bool A=1,B=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;a[0]=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) A=0;
		if(a[i]>1) B=0;
	}
	if(A){cout<<n/2;return 0;}
	if(B){
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0 || (a[i] && (a[i]==a[i-1]))){
					ans++;
				}
			}
		}
		else{
			for(int i=1;i<=n;i++){
				if(a[i]) ans++;
			}
		}
		cout<<ans;return 0;
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k) ans++;
	}
	cout<<ans;
	return 0;
}
