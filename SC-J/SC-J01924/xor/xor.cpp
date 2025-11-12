#include<bits/stdc++.h>
using namespace std;
int n,k,a[100010],vis[100010],cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			cnt++;
			vis[i]=1;
		}
	}
	int d=0;
	for(int i=1;i<=n;i++){
		if(vis[i]){
			if(k==0) d=-1;
			else d=0;
		}
		else{
			if(d==-1) d=0;
			d=a[i]^d;
			vis[i]=1;
		}
		if(d==k){
			cnt++;
			if(k==0) d=-1;
			else d=0;
		}
	}
	cout<<cnt;
	return 0;
}