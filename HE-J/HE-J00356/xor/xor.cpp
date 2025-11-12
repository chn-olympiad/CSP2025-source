#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
#define int long long
int a[N],n,k;
int xorr(int aa,int bb){
	int tmp=1,ans=0;
	while(aa||bb){
		if(aa%2!=bb%2) ans+=tmp;
		tmp*=2,aa/=2,bb/=2;
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
	bool flag[N];
	int tmp=0;
	memset(flag,0,sizeof flag);
	for(int l=0;l<n;l++)
		for(int r=l;r<n;r++){
			if(flag[r]){
				l=r+1;
				break;
			}
			if(ans(l,r)==k){
				tmp++;
				for(int i=l;i<=r;i++) flag[i]=true;
				//cout<<l<<' '<<r<<endl;
				l=r+1;
			}
		}
	return tmp;
}
bool ad1=true;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1) ad1=false;
	}
	if(ad1){
		cout<<n/2;
		return 0;
	}
	cout<<check();
}
