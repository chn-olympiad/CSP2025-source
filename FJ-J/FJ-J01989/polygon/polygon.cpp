#include<bits/stdc++.h>
using namespace std;
int n,a[5001],h,z[5001];
void w(int l,int x){
	if(x>n){
		return;
	}
	if(l>=3){
		int maxn=0,ans=0;
		for(int i=1;i<=l;++i){
			ans+=z[i];
			maxn=max(maxn,z[i]);
		}
		if(ans>maxn*2){
			h++;
		}
	}
	for(int i=1;i<=n-2;++i){
		if(x+i>n){
			return;
		}
		z[l+1]=a[x+i];
		w(l+1,x+i);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	w(0,0);
	cout<<h;
	return 0;
}
