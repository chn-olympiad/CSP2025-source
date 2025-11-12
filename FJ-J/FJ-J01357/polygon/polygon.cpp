#include<bits/stdc++.h>
using namespace std;
int n,daan=0;
const int ms=998244353;
int a[5005];
void dg(int h,int z,int maxz,int gs){
	if(h==n){
		if(gs<3){
			return;
		}
		if(maxz*2<z){
			daan++;
		}
	}else{
		dg(h+1,z,maxz,gs);
		dg(h+1,z+a[h],max(maxz,a[h]),gs+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	bool pd=true;
	for(int i=0;i<n;i++){
		cin >> a[i];
		if(a[i]!=1){
			pd=false;
		}
	}
	if(pd){
		long long daan=0;
		long long xz=1;
		for(int i=3;i<=n;i++){
			xz=1;
			for(int j=0;j<i;j++){
				xz*=(n-j);
				xz%=ms;
			}
			daan+=xz;
			daan%=ms;
		}
		cout << daan;
		return 0;
	}else{
		dg(1,0,0,0);
		dg(1,a[0],a[0],1);
		cout << daan;
	}
	return 0;
}

