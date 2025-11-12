#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int n,m,l;
int a[107];
int b[17][17];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	l=a[1];
	sort(a+1,a+1+n*m);
	int s=n*m;
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				b[i][j]=a[s];
				s--;
			}
		}
		else{
			for(int i=n;i>=1;i--){
				b[i][j]=a[s];
				s--;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==l){
				cout<<j<<" "<<i<<endl;
				return 0;
			}
		}
	}
	return 0;
}
