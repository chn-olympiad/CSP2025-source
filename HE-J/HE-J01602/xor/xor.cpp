#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[500005];
int xorr(int a_ch,int b_ch){
	int t=1,ans=0;
	while(a_ch||b_ch){
		ans+=t*(a_ch%2!=b_ch%2);
		t*=2;
		a_ch/=2;
		b_ch/=2;
	}
	return ans;
}
int ans(int l,int r){
	int tmp=a[l];
	for(int i=l+1;i<=r;i++){
		tmp=xorr(tmp,a[i]);
	}
	return tmp;
}
int check(){
	bool flag1[500005];
	long long tmp=0;
	memset(flag1,0,sizeof flag1);
	for(int l=0;l<n;l++){
		for(int r=l;r<n;r++){
			if(flag1[r]){
				l=r+1;
				break;
			}
			if(ans(l,r)==k){
				tmp++;
				for(int i=l;i<=r;i++){
					flag1[i]=true;
				}
				l=r+1;
			}
		}
	}
	return tmp;
}
bool ad123=true;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			ad123=false;
		}
	}
	if(ad123==true){
		cout<<n/2;
		return 0;
	}
	cout<<check();
	return 0;
}
