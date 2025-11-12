#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[200005],y=1,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)y=0;
		}
	if(k==0&&y==1){
		cout<<n/2;
		return 0;
	}
	if(k==0){
		for(int i=1;i<=n;i++)if(a[i]==1)ans++;
	}
	if(k==1){
		for(int i=1;i<=n;i++)if(a[i]==1)ans=ans+2;
	}
	cout<<ans/2;
	return 0;

}
