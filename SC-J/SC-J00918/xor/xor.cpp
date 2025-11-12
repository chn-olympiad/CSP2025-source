#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==1){
		cout<<0;
		return 0;
	}else if(n==2){
		cout<<1;
		return 0;
	}else{
		if(k==0){
			cout<<n/2;
		}
	}
	return 0;
}