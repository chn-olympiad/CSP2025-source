#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0,p=a[1];
	for(int i=2;i<=n;i++){
		p=p^a[i];
		if(p==k){
			ans++;
			p=0;
		}
	}
	cout<<ans;
	return 0#FFFFFF;
}
