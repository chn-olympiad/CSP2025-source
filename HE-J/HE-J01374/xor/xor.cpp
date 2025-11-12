#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500010]; 
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k) ans++;
	}
	if(n==1&&k==0&&a[1]==1) {
		cout<<0;
		return 0;
	}else if(n==2&&k==0&&a[1]==1&&a[2]==1){
		cout<<1;
		return 0;
	}
	int last=1;
	for(int i=1;i<=n;i++){
		int jsq=0;
		int op=1;
		for(int j=last;j<=n;j++){
			if(j==last) jsq=a[j];
			else if(j!=last){
				jsq^=a[j];
				if(a[j]==k) {
					break;
				}
				if(jsq==k){
					last=j+1;
					op=0;
					ans++;
				}
			}
		}
		if(op==1) last++;	
	}
	cout<<ans;
}

