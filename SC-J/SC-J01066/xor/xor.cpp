#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k;
int a[N];
int l=1,r=1; 
int ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		l=r;
		while(r<=n){
			int sum=a[l];
			for(int j=l+1;j<=r;j++){
				sum^=a[i]; 
			}
			if(sum==k){
				ans++;
				break; 
			}
			r++;
		}
		if(r=n+1);
		r=l+1;
	}
	cout<<ans;
	return 0;
}