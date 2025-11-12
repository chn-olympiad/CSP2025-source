#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k, a[500005];
int b[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(k==0){
		bool asd=0;
		for(int i=1;i<=n;i++){
			if(a[i]!=1){
				asd=1;
				break;
			}
		}
		if(asd==0){
			if(n%2==0){
				cout<<n;
				return 0;
			}
			else{
				cout<<n-1;
				return 0;
			}
		}
		else{
			int j=0;
			for(int i=1;i<n;i++){
				if(a[i]!=a[i+1]){
					j++; b[j]=1;
					a[i+1]=1;
				}
				else if(a[i]==a[i+1]){
					j++; b[j]=0;
					a[i+1]=0;
				}
			}
			for(int i=n;i>=1;i--){
				if(a[i]==k){
					cout<<i;
					return 0;
				}
			}
		}
	}
	else if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==a[i+1]){
				a[i+1]=0;
			}
			else{
				a[i+1]=1;
			}
		}
		int g=1, maxn=0;
		for(int i=2;i<=n;i++){
			g++;
			if(a[i]==1){
				maxn=max(g,maxn);
				g=0;
			}
		}
		cout<<maxn;
	}
	return 0;
}

