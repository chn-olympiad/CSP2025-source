#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[114][514],b[114],c,k;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	c=b[1];
	sort(b+1,b+1+n*m,greater<int>());
	for(int i=1;i<=m;i++){
		if(i%2){
			for(int j=1;j<=n;j++){
				k++;
				a[i][j]=b[k];
				if(b[k]==c){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				k++;
				a[i][j]=b[k];
				if(b[k]==c){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
