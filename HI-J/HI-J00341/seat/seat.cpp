#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],cnti,wj;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	wj=a[1];
	cnti=n*m+1;
	sort(a+1,a+n*m+1);
	for(int i=1;i<=m/2;i++){
		for(int j=1;j<=n;j++){
			cnti--;
			if(a[cnti]==wj){
				cout<<i<<" "<<j;
				return 0;
			}
		}
		i++;
		for(int j=n;j>=1;j--){
			cnti--;
			if(a[cnti]==wj){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	if(m%2==1){
		for(int j=1;j<=n;j++){
			cnti--;
			if(a[cnti]==wj){
				cout<<m<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}
