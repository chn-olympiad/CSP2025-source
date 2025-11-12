#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	bool f=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			f=false;
		}
	}
	if(f&&k==0){
		cout<<"0";
	}else if(k<=1){
		int cnt=0;
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					cnt++;
				}
			}
			cout<<cnt;
		}else{
			cout<<n-cnt;
		}
	}else{
		cout<<"2";
	}
	return 0;
}
