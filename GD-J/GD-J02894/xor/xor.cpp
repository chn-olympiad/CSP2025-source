#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	int ans=0;
	int nums[n+5]={0};
	for(int i=1;i<=n;i++){
		cin>>nums[i];
	}
	int xors[n+5]={0};
	xors[1]=nums[1];
	for(int i=2;i<=n;i++){
		xors[i]=(xors[i-1]^nums[i]);
	}
//	for(int i=1;i<=n;i++){
//		cout<<setw(4)<<i;
//	}
//	cout<<endl;
//	for(int i=1;i<=n;i++){
//		cout<<setw(4)<<xors[i];
//	}
	int l,r;
	for(l=0;l<n;l++){
		for(r=l+1;r<=n;r++){
			if((xors[l]^xors[r])==k){
//				cout<<xors[l]<<' '<<xors[r]<<endl;
//				cout<<l<<' '<<r<<endl<<endl;
				ans++;
				l=r;
			}
		}
	}
	cout<<ans;
	return 0;
}
