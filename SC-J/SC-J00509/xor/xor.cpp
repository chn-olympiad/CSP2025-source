#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;

int main(){
	int n,k,ans=0;
	int a[N];
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1) ans++;
			if(a[i]==0&&a[i+1]==0){
				ans++;
				i+=2;
			}
		}
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0) ans++;
			if(a[i]==1&&a[i+1]==1){
				ans++;
				i+=2;
			}
		}		
	}
	cout<<ans;
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdin);
	return 0;
}