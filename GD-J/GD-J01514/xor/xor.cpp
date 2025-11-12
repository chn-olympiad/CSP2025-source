#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
int a[1000005],d[1000005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=n;i++){
		if(a[i]==k) ans++;
		else{
			d[i]=max(d[i]^a[i+1],a[i]^a[i+1]);
			
		}
	}cout<<ans;
	return 0;
}

