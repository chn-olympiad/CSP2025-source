#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[500001],jsq=0,ans=0,res=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int q=n;q>=1;q--){
		jsq=0;
		for(int i=q;i>=1;i--){
			ans=0;
			for(int j=i;j>=1;j--){
				ans^=a[j];
				if(ans==k){
					jsq++;
					i=j;
					break;
				}
			}
		}
		res=max(jsq,res);	
	}
	
	cout<<res;
	return 0;
}
