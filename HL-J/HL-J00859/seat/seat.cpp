#include <bits/stdc++.h>
using namespace std;
const int N=1000;
int n,m,a[N],cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>=a[1]) cnt++;
	}
	int ans=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				cnt-=1;
				//cout<<i<<' '<<j<<' '<<cnt<<endl;
				if(cnt==0){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
		if(i%2==0){
			for(int j=n;j>=1;j--){
				cnt-=1;
				//cout<<i<<' '<<j<<' '<<cnt<<endl;
				if(cnt==0){
					cout<<i<<' '<<j;
					return 0;
				}				
			}
		}
	}
	return 0;
}