#include<bits/stdc++.h>
using namespace std;
int a[500100];
int yxh(int x,int y){
	int cnt=a[x];
	for(int i=x+1;i<=y;i++){
		cnt=(cnt ^ a[y]);
	}
	return cnt;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int ans=0;
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int l=1,r=1;
	while(l<=r&&l<=n&&r<=n){
		if(yxh(l,r)==k){
			ans++;
			l=r;
		}
		if(r==n){
			l++;
			r=l;
		}else{
			r++;
		}
	}
	cout<<ans;
	return 0;
}
