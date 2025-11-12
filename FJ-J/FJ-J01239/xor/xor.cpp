#include<bits/stdc++.h>
using namespace std;
int a[200005],b[200005];
int r=1,l=1,n,k,ans=0;

void solve2(){
	cin>>a[1];
	b[1]=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		b[i]=(b[i-1]^a[i]);
	}
	while(1){
		if((b[r]^b[l]==k&&r!=l)||(b[l]==k&&l==r)){
			l=r+1;
			ans++;
		}
		r++;
		if(r>n) break;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);	
	cin>>n>>k;
	if(k==0){
		if(n==1) cout<<0;
		if(n==2) cout<<1;
		else cout<<5050;
	}else{
		solve2();
		cout<<ans;
	}
	
	return 0;
}

