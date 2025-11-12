#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],ansi,ansj;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1],cnt=n*m;
	sort(a+1,a+1+n*m);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[cnt--]==r){
					ansi=i;
					ansj=j;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				if(a[cnt--]==r){
					ansi=i;
					ansj=j;
				}
			}
		}
	}
	cout<<ansi<<" "<<ansj;
	return 0;
}