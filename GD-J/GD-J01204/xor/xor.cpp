#include<bits/stdc++.h>
using namespace std;
int a[1001000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
//	if(k==0){
//		cout<<n/2;
//		return 0;
//	}
	int ans=0,tmp;
	for(int i=1;i<=n;i++){
		if(i==1){
			if(a[i]==k){
				ans++;
				i++;
			}
			tmp=a[i];
		}
		else{
			tmp^=a[i];
			if(tmp==k){
				ans++;
				i++;
				tmp=a[i];
			}
		}
	}
	cout<<ans;
	
	return 0;
}

