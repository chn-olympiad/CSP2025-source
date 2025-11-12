#include<algorithm>
#include<iostream>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	int n,m,nm,ii,a[110],r;
	cin>>n>>m;
	nm=n*m;
	r=nm;
	for(int i=1;i<=nm;i++)
		cin>>a[i];
	ii=a[1];
	sort(a+1,a+1+nm);
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				if(a[r]==ii){cout<<j<<' '<<i<<endl; return 0;}
				r--;
			}
		}
		else {
			for(int i=n;i>=1;i--){
				if(a[r]==ii){cout<<j<<' '<<i<<endl; return 0;}
				r--;
			}
		}
	}
	return 0;
}
