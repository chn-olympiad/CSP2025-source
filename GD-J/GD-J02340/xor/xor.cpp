#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+10;
int head=1,n,k,ans;
int a[N],h[N];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		bool flag=false;
		h[i]=a[i];
		if(h[i]==k)flag=true;
		if(!flag){
			for(int j=head;j<=i-1;j++){
				h[j]^=a[i];
				if(h[j]==k){
					flag=true;
					break;
				}
			}
		}
		if(flag){
			head=i+1;
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
