#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[110][110],b[110],c;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
		b[i]=-b[i];
	}
	int k=b[1];
	sort(b+1,b+n*m+1);
	for(int i=1;i<=n;i++){
		if(i&1){
			for(int j=1;j<=m;j++){
				a[j][i]=b[++c];
				if(b[c]==k){
					cout<<i<<' '<<j;
					break;
				}
			}
		}else{
			for(int j=m;j>=1;j--){
				a[j][i]=b[++c];
				if(b[c]==k){
					cout<<i<<' '<<j;
					break;
				}
			}
		}
	}
	return 0;
}
