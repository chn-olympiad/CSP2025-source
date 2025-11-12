#include<bits/stdc++.h>
using namespace std;
long long n,k,l=1,r=1;
long long ans;
long long a[500005];
long long b[500005];
bool vis[500005];
bool check(int ll,int rr){
	for(int i=ll;i<=rr;i++){
		if(vis[i])return false;
	}
	return true;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]^a[i];
	}
	for(int s=1;s<=n;s++){
		for(l=1;l+s-1<=n;l++){
			
			r=l+s-1;
			if(vis[l]||vis[r])continue;
			//cout<<l<<" "<<r<<endl;
		//	cout<<ans<<check(l,r)<<endl;
		long long ww=b[r]^b[l-1];
			if(ww==k&&check(l,r)){
				ans++;
				for(int i=l;i<=r;i++){
					vis[i]=1;
				}
			}
		}
	}
	cout<<ans;
	return 0;
} 
