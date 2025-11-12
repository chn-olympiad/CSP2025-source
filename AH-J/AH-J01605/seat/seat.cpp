#include <bits/stdc++.h>
using namespace std;
const int N=110;
int n,m,s[N],rk=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++){
		cin>>s[i];
		rk+=(s[i]>s[1] ? 1 : 0);
	}
	bool f=0;
	for (int i=1;i<=m;i++){
		if (i&1){
			for (int j=1;j<=n;j++){
				rk--;
				f=rk;
				if (!f){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
		else{
			for (int j=n;j>=1;j--){
				rk--;
				f=rk;
				if (!f){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
