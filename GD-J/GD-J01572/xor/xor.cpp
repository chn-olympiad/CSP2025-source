#include<bits/stdc++.h>
using namespace std;
const int kmaxN = 5e5+10;
int n,k,ans;
int a[kmaxN];
bool f = 1,ff = 1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		if(a[i] > 1) f = 0;
		if(a[i] != 1) ff = 0;
	}
	if(ff){
		cout<<n/2;
	}else{
		if(f){
			if(!k){
				int xn = n;
				for(int i = 1;i <= n;i++){
					if(!a[i]) ans++;
					else{
						int sum = 0;
						while(a[i] == 1){
							sum++;
							i++;
						}
						i--;
						ans+=sum/2;
					}
				}
				cout<<ans;
			}else{
				for(int i = 1;i <= n;i++) if(a[i]) ans++;
				cout<<ans;
			}
		}else{
			int xx = 0;
			for(int i = 1;i<=n;i++){
				xx ^= a[i];
				if(a[i] == k || xx == k){
					ans++;
					xx = 0;
				} 
			}
			cout<<ans;
		}
	}
	
	return 0;
} 
/*
100 1

1 0 1 1 0 0 0 1 1 1 1 1 1 0 0 1 1 1 1 1 0 0 1 1 1 0 0 1 1 1 1 0 1 0 1 1 1 0 1 1 1 1 0 1 0 0 1 1 1 0 1 1 1 0 1 0 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 1 0 1 1 0 1 1 1 1 0 1 1 0 1 0 1 1 0 0 0 0 1
*/
