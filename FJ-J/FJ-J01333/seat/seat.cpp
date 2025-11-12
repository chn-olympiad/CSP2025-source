#include<bits/stdc++.h>
using namespace std;
long long fs[105];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,zr=1,f,xb=1;
	cin>>n>>m;
	zr=n*m;
	for(int i=1;i<=zr;i++){
		cin>>fs[i];
	}
	f=fs[1];
	sort(fs+1,fs+zr+1,cmp);
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				if(fs[xb]==f){
					cout<<j<<" "<<i;
					return 0;
				}
				xb++;
			}
		}else{
			for(int i=n;i>=1;i--){
				if(fs[xb]==f){
					cout<<j<<" "<<i;
					return 0;
				}
				xb++;
			}
		}
	}
//	100  99 (98) 97
//	100
//	99
	return 0;
}
