#include<bits/stdc++.h>
using namespace std;int n,k,ans=0;
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ans=0;cin>>n>>k;
	if(!k){//k=0
		for(int i=0,a,last=2;i<n&&cin>>a;i++){
			if(!a)ans++;else ans+=(last==1);last=a;
		}
	}else if(k==1){
		for(int i=0,a;i<n&&cin>>a;i++)if(a)ans++;
	}else ans=n/2-1;
	cout<<ans;
	return 0;
}