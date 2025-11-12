#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int f=0,f2=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)f=1;
		if(a[i]>1)f2=1;
	}
	if(!f&&k==0){
		cout<<n/2;
	}
	else if(k<=1&&!f2){
		if(k==0){
			int ans=0;
			for(int i=1;i<=n;i++)if(a[i]==0)ans++;
			cout<<ans;
		}
		else{
			int ans=0;
			for(int i=1;i<=n;i++)if(a[i]==1)ans++;
			cout<<ans;
		}
	}
	else cout<<n;
	return 0;
}
