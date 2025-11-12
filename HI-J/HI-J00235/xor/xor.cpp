#include<bits/stdc++.h>
using namespace std;
int n,k,ans=0;
int a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int l=0;
	for(int i=0;i<n;i++){
		l=l^a[i];
		if(l==k){
			l=0;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
