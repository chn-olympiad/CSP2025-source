#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int n,k,ans,a[N];
bool flag0,flag1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) flag0 = true;
		else if(a[i]==1) flag1 = true;
	}
	if(k==0){
		if(flag0&&flag1){
			for(int i=1;i<=n;i++){
				if(a[i]==0) ans++;
			}
			cout<<ans;
			return 0;
		}else if(flag0){
			cout<<n;
			return 0;
		}else if(flag1){
			cout<<n/2;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}else if(k==1){
		if(flag0&&flag1){
			for(int i=1;i<=n;i++){
				if(a[i]==1) ans++;
			}
			cout<<ans;
			return 0;
		}else if(flag0){
			cout<<n/2;
			return 0;
		}else if(flag1){
			cout<<n;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}
	return 0;
}
