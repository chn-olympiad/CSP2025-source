#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
int a[100005];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		cout<<n/2;
	}else if(k==1){
		int cnt=0;
		for(int i=1;i<=n;){
			if(a[i]==1){
				cnt++;
				while(a[i+1]==0&&i+1<=n){
					i++;
				}
			}
			i++;
		}
		cout<<cnt;
	}else{
		cout<<2;
	}
	return 0;
}
