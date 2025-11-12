#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,k,a[N],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(k==0){
		for(int i=1;i<=n;i++)if(a[i]==0)ans++;
		cout<<ans;
	}else if(k==1){
		for(int i=1;i<=n;i++)if(a[i]==1)ans++;
		cout<<ans;
	}else {
		int s=0;
		for(int i=1;i<=n;i++)s+=a[i];
		int l=s/n;
		if(n*l<s)cout<<l+1;
		else cout<<l;
	}
}
