#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,a[555555],ans,w[555555],wix,winx;
int main(){
	freopen("xor.in","r",stdin);freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==k){
			ans++;
			w[wix]=i;wix++; 
		} 
	}
	for(int i=0;i<n;i++){
		if(w[winx]<=i){
			winx++;
			continue;
		}
		int xorsum=i; 
		for(int j=i+1;j<w[winx];j++){
			xorsum^=j;
			if(xorsum==k){
				ans++,i=j;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
} 
