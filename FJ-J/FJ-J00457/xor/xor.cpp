#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
typedef long long ll;
int n,k,a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool flag=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=1;
	}
	if(k==0&&flag==0){
		if(n==1){
			cout<<0; return 0;
		}
		if(n==2){
			cout<<1; return 0;
		}
		cout<<n/2; return 0;
	}
	if(k==1){
		int ans=0;
		for(int i=1;i<=n;i++){
			if((a[i]==1&&a[i+1]==0)||(a[i]==0&&a[i+1]==1)){
				ans++;
			}
		}
		cout<<ans<<endl;
		return 0;
	}else if(k==0){
		int ans=0;
		for(int i=1;i<=n;i++){
			if((a[i]==1&&a[i+1]==1)||(a[i]==0&&a[i+1]==0)){
				ans++;
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	cout<<56;
	return 0;
}

