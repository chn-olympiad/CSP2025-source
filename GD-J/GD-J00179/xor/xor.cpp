#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int ans=0;
	int a[1000]={0};
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans+=i;
	}
	cout<<ans;
}
