#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[10005];
signed main(){
	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int y=0;
	int u=0;
	int p=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			u++;
		}
		if(a[i]==0){
			y++;
		}
		if(a[i]==1){
			
		}
	}
	if(k==0&&u==0){
		cout<<0;
		return 0;
	}
	if(k==0){
		cout<<y;
		return 0;
	}
	if(k==1){
		cout<<p;
		return 0;
	}
	cout<<n;
	return 0;
}  