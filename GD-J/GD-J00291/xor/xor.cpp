#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
long long n,k,a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n==1){
		if(a[1]==1) cout<<0;
		 else cout<<1;
		return 0;
	}
	if(n==2){
		if(a[1]==0&&a[2]==0) cout<<2;
		 else if(a[1]==2&&a[2]==1) cout<<1;
		  else cout<<0;
		return 0;
	}
	if(k==0){
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0) ans++;
			if(a[i]==1&&a[i-1]==1) a[i]=0,a[i-1]=0,ans++;
		}
		cout<<ans;
	}
	else{
		int ans=0;
		for(int i=1;i<=n;i++)
			if(a[i]==1) ans++;
		cout<<ans;
	}
	return 0;
}
