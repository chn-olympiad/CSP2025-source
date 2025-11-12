#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int n,k,a[maxn],ans;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	if(k==0){
		int vis=0;
		for(int i=1;i<=n;++i){
			if(a[i]==0){
				ans++;
				vis=0;
			}else{
				vis++;
				if(vis==2){
					ans++;
					vis=0;
				}
			}
		}
	}else{
		for(int i=1;i<=n;++i){
			if(a[i]){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}