#include <bits/stdc++.h>
using namespace std;
long long n,k,a[500005],ans,l,r,lx,rx;
void yhh(){
	int cnt=0,w=1;
	while(w<=n){
		for(int j=w;j<=n;j++){
			cnt^=a[j];
			if(cnt==k){
				w=j+1;
				ans++;
				break;
			}
		}
		cnt=0;
	}
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	yhh();
	cout<<ans;
	return 0;
}
