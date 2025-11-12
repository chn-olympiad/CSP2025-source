#include<bits/stdc++.h>
using namespace std;
const int mo=998244353;
int n,ans=0;
int a[5000];
int le(int l,int r){
	int le=0;
	for(int z=l;z<=r;z++){
		le+=a[z];
	}return le;
}
int ma(int l,int r,int m){
	int ma=0;
	for(int z=l;z<=r;z++){
		if(z==m)continue;
		ma=max(ma,a[z]);
	}return ma;
}
int main(){
	freopen("polygon4.in","r",stdin);
	freopen("polygon4.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}sort(a,a+n);
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			int lenth=le(i,j);
			if(lenth>2*ma(i,j,-1)){
				ans++;
			}for(int m=i;m<=j;m++){
				if(j-i>3&&lenth-a[m]>2*ma(i,j,m))ans++;
			}
		}
	}
	printf("%d",ans-1%mo);
	return 0;
}
