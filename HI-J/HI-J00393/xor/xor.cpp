#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],c=0,t=1,ans=0; 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	a[n+1]=k;
	for(int i=1;i<=n+1;i++){
		if(a[i]==k){
			ans++;
			int c=0;
			for(int q=i-1;q>=t;q--){
				c=c^a[q];
				if(c==k){
					c=0;
					ans++;
				}
			}
			t=i+1;
		}	
	}
	cout<<ans-1;
	return 0;
}
