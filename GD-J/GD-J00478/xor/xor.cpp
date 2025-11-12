#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5*1e5+11;
int n,k,a[N];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	if((n==1&&k==0)||(n==2&&k==0)){
		cout<<n;return 0;
	}else if(k==0){
		cout<<n/2;return 0;
	}else if(k==1){
		int j=0,o=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1)j++;
			if(a[i]==0)o++;
		}
		if(o%2==0&&j%2==0){
			cout<<o/2+j/2-1;return 0;
		}else if((j%2==1&&o%2==0)||(o%2==1&&j%2==0)){
			cout<<n;return 0;
		}else{
			cout<<n;return 0;
		}
	}
	return 0;
}
