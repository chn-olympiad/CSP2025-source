#include<bits/stdc++.h>
using namespace std;
int n,k,ans,m,flag;
int a[500010],vis[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i=0;i<n;i++){
		if(a[i]==k){
			ans++;
			vis[i]=1;
		}
	}
	for(int i=0;i<n;i++){
		if(vis[i]==1){
			m=0;
			flag=0;
			continue;
		}
		if(flag==0){
			m=a[i];
			flag=1;
		}else{
			if((a[i]^m)==k){
				ans++;
				m=0;
				flag=0;
			}else{
				m = a[i]^m;
			}
		}
	}
	cout << ans;
	return 0;
}
