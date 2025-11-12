#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int lll=a[1];
	sort(a+1,a+1+n*m);
	int ii=1,jj=1,cnt=n*m;
	while(jj<=m){
		for(;ii<=n;ii++){
			if(lll==a[cnt]){
				cout<<jj<<' '<<ii;
				return 0;
			}
			cnt--;
		}
		ii--;
		jj++;
		for(;ii>=1;ii--){
			if(lll==a[cnt]){
				cout<<jj<<' '<<ii;
				return 0;
			}
			cnt--;
		}
		ii++;
		jj++;
	}
	return 0;
}
//seat