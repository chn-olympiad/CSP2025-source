#include <bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int n,k,a[maxn],xo[maxn],ans,B,C;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >>n>>k;
	B=1; C=1; ans=0;
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		if(a[i]>1) B=0;
		if(a[i]>255) C=0;
	}
	if(B){
		for(int i=1;i<=n;i++)
			if(a[i]) ans++;
		cout <<ans;
		return 0;
	}
	for(int i=1;i<=n;i++) xo[i]=(xo[i-1]^a[i]);
	int lastr=0;
	for(int r=1;r<=n;r++){
		for(int l=lastr+1;l<=r;l++){
			if((xo[r]^xo[l-1])==k){
				ans++;
				lastr=r;
				break;
			}
		}
	}
	cout <<ans;
	return 0;
}
