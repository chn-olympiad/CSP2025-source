#include<bits/stdc++.h>
using namespace std;
long long n,k,a[100860],ans,num,w=-1;
int q(int l,int r){
	int u=a[l];
	for(int i=l+1;i<=r;i++){
		u^=a[i];
	}
	return u;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(q(i,j)==k){
				ans++;
				i=j+1;
			}
		}
	}
	cout<<ans;
	return 0;
}