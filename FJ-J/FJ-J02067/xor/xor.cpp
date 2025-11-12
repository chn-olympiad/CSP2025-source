#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[500005],ans=0,l=-1;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			ans++;
			l=-1;
		}else if(l==-1){
			l=a[i];
		}else{
			l^=a[i];
			if(l==k){
				ans++;
				l=-1;
			}
		} 
	}
	cout<<ans;
}
