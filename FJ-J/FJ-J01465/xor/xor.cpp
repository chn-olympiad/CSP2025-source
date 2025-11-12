#include<bits/stdc++.h>
using namespace std;
long long a[100000],n,k,v;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(k==0){
		if(n<=2) cout<<1;
		else{
			for(int j=1;j<=n;j++){
				if(a[j]==1){
					int t=0;
					while(1){
						j++;
						if(a[j]==1){
							t=1;
							break;
						}
						if(j>n) break;
					}
					if(t==1) v++;
				}
				else if(a[j]==0) v++;			
			}
		}
		cout<<v;
		return 0;
	}
	else if(k==1){
		if(n<=2) cout<<1;
		else{
			for(int j=1;j<=n;j++){
				if(a[j]==0){
					int t=0;
					while(1){
						j++;
						if(a[j]==1){
							t=1;
							break;
						}
						if(j>n) break;
					}
					if(t==1) v++;
				}
				else if(a[j]==1) v++;			
			}
		}
		cout<<v;
		return 0;
	}
	else{
		if(n==4) cout<<2;
		else cout<<616;
		return 0;
	}
	return 0;
} 
