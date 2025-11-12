#include<bits/stdc++.h>
using namespace std;
struct xr{
	int fs=0;
	int isxr=0;
};
xr a[120];
int b[15][15];
bool cmp(xr a,xr b){
	return a.fs>b.fs;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].fs;
		if(i==1){
			a[i].isxr=1;
		}
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].isxr==1){
			if(i%n==0){
				if((i/n)%2==0){
					cout<<i/n<<" 1";
					break;
				}else{
					cout<<i/n<<" "<<n;
					break;
				}
			}else{
				if((i/n)%2==0){
					cout<<i/n+1<<" "<<i%n;
					break;
				}else{
					cout<<i/n+1<<" "<<n-i%n+1;
					break;
				}
			}
		}
	}
	return 0;
}
