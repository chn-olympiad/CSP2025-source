#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long n,a[N],ans,sm,k,vis[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			ans++;
			vis[i]=1;
		}
	}
	for(long long l=1;l<=n;l++){
		sm=0;
		if(vis[l]!=0)
			continue;
		for(long long r=l;r<=n;r++){
			if(vis[r]!=0){
				l=r;
				break;
			}
			sm=sm^a[r];
			if(sm==k){
				l=r;
				ans++;
				break;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
