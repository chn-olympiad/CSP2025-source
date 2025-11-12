#include<bits/stdc++.h>
using namespace std;
int a[100010];
int n,k,ans,ok;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(k==1){
		for(int i=1;i<=n;i++) if(a[i]==1) ans++;
		cout<<ans;
	}else if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==1&&ok!=1){
				ok=1;
			}else if(a[i]==1&&ok==1){
				ans++;
				ok=0;
			}
		}
		cout<<ans;
	}
	return 0;
}
//1 0 1 1 0 1 1 0
