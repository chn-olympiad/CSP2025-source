#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,k,a[N],ans;
bool A(){
	if(k!=0)return false;
	for(int i=1;i<=n;i++){
		if(a[i]!=1){
			return false;
		}
	}
	return true;
}
bool B(){
	for(int i=1;i<=n;i++){
		if(a[i]>1){
			return false;
		}
	}
	return true;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(A()){
		cout<<n/2;
		return 0;
	}
	if(B()){
		int cnt=0;
		if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1)cnt++;
			}
		}
		else{
			for(int i=1;i<=n;i++){
				if(a[i]==0)cnt++;
				else if(a[i]==1&&a[i+1]==1){
					int w=1;
					while(a[i]==1){
						w++;
						i++;
					}
					cnt+=w/2;
					i--;
				}
			}
		}
		cout<<cnt;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int xx=a[i];
		if(xx==k){
			ans++;
			continue;
		}
		for(int j=i+1;j<=n;j++){
			xx^=a[j];
			if(xx==k){
				i=j;
				ans++;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
} 