#include<bits/stdc++.h>
using namespace std;
const int N=5e5+33;
int n,k;
int a[N];
int f[N];
int ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	int j=0;
	int last=1;
	bool flag=1;
	int cnt=0,cntt=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1) flag=0;
		f[i]=a[i]^f[i-1];
	}
	if(flag==1){
		for(int i=1;i<=n;i++){
			if(f[i]^f[i-1]==k){
				ans++;
			}
		}
	}else{
		for(int i=1;i<=n;i++){
			for(j=last;j<=i;j++){
				if((f[i]^f[j-1])==k){
					ans++;
					last=i+1;
					break;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
