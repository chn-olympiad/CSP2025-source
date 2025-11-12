#include<bits/stdc++.h>
using namespace std;
long long n,m,l,me,a[20000800],ans[2008][2008];
string s;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		me=a[1];
	}
	sort(a+1,a+1+n*m);
	l=n*m;
	for(int j=1;j<=m;j++){
		if(j%2==0){
			for(int i=n;i>=1;i--){
				ans[i][j]=a[l--];
			}	
		}
		else{
			for(int i=1;i<=n;i++){
				ans[i][j]=a[l--];
			}	
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			//cout<<ans[i][j]<<" ";
			if(ans[i][j]==me) {
				cout<<j<<" "<<i;
				////return 0;
			}
		}
		//cout<<"\n";
	}
}
