#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,a[N],k,b[N];
bool fs=1,ft=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if (a[i]!=1)fs=0;
		if (a[i]>1)ft=0;
	}
	if (fs){
		cout<<n/2;
	}else if (ft){
		int ans=0;
		if (k==0){
			int x=0;
			for (int i=1;i<=n;i++){
				if (a[i]==0){
					ans++;
					x=0;
				}else{
					x++;
					if (x>=2){
						ans++;
						x-=2;
					}
				}
			}
		}else{
			for (int i=1;i<=n;i++){
				if (a[i]==1)ans++;
			}
		}
		cout<<ans;
	}else{
		int ans=0;
		for (int i=1;i<=n;i++){
			if (a[i]==k)ans++;
		}
		cout<<ans;
	}
	return 0;
} 
