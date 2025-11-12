#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,a[N],f,f0[N],f00;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			f++;
			f0[++f00]=i;
		}
	}
	
	f0[0]=0;
	if(k==0 && f==0){
		cout<<n/2;
		return 0;
	}else if(k==0){
		int ans=0;
		for(int i=1;i<=f00;i++){
			ans+=(f0[i]-f0[i-1]-1)/2;
		}
		ans+=f00;
		cout<<ans;
		return 0;
	}
	if(k==1){
		int ans=n;
		ans-=f00;
		cout<<ans;
		return 0;
	}
}
