#include<bits/stdc++.h>
using namespace std;

const int N=5*10e5;
int n,k;
int a[N];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1) cout<<1;
	else if(n==2){
		if(a[1]==a[2]){
			cout<<2;
		}else cout<<1; 
	}else if(k==0){
		int maxx=0;
		int qt=a[1];
		int ans=1;
		for(int i=2;i<=n;i++){
			if(qt==a[i]){
				ans++;
				maxx=max(maxx,ans);
			}else{
				qt=a[i];
				ans=1;
			}
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
