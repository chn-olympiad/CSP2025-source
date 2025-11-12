#include<bits/stdc++.h>
using namespace std;
#define int long long

int a[5000000];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int nn,k,ans=0,no=-1;
	memset(a,-1,sizeof(a));
	cin>>nn>>k;
	for(int i=0;i<nn;i++){
		cin>>a[i];
	}
	int n=nn;
	for(int l=0;l<n;l++){
		if(l<=no) continue;
		for(int r=l;r<n;r++){
			if(l<=no) break;
			int x=0;
			for(int i=l;i<=r;i++){
				x^=a[i];
			}
			if(x==k){
				ans++;
				no=r;
			}
		}
	}
	cout<<ans;
	return 0;
}

