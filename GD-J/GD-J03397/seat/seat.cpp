#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,R;
int num[101];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>num[(i-1)*n+j];
		}
	}
	R=num[1];
	int cnt=1;
	sort(num+1,num+1+n*m,greater<int>());
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				if(num[cnt]==R){
					cout<<i<<" "<<j;
					return 0;
				}
				cnt++;
			}
		}
		else{
			for(int j=1;j<=n;j++){
				if(num[cnt]==R){
					cout<<i<<" "<<j;
					return 0;
				}
				cnt++;
			}
		}
	}
}
