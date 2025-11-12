#include"bits/stdc++.h"
using namespace std;
int n,m,a[105],b;
bool ok=1;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;      //n-hang  m-lie
	for(int i=1;i<=n*m;++i) cin>>a[i];
	b=a[1];
	std::stable_sort(a+1,a+1+(n*m),cmp);
	int i=1,j=1,k=1;// i-lie  j-hang  k-ji_shu
	for(i=1;i<=m && ok;++i){
		if(i%2==1){
			for(j=1;j<=n && ok;++j,++k){
				if(a[k]==b){
					cout<<i<<" "<<j<<"\n";
					ok=0;
				}
			}
		}
		else {
			for(j=n;j>0 && ok;--j,++k){
				if(a[k]==b){
					cout<<i<<" "<<j<<"\n";
					ok=0;
				}
			}
		}
	}
	return 0;
}
