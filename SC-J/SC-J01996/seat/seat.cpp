#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c;
	int l[105];
	cin>>n>>m>>c;
	l[1]=c;

	for(int i=2;i<=n*m;i++){
		cin>>l[i];
	}
	sort(l+1,l+1+n*m);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(i%2==0){
				if(l[m*n-i*m+j]==c){
					cout<<i<<' '<<j;
				}
			}
			else{
				if(l[m*n-(i-1)*m-j+1]==c){
					cout<<i<<' '<<j;

				}
			}
		}
		
	}
	
	return 0;
}