#include<bits/stdc++.h>
using namespace std;
#define _ long long
_ n,m,a[105],k;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	//input
	cin>>n>>m;
	for(_ i=1;i<=n*m;i++){
		cin>>a[i];
	}k=a[1];
	
	//sort
	sort(a+1,a+(n*m)+1,greater<_>());
	//seat
	for(_ i=1;i<=n;i++){
		for(_ j=1;j<=m;j++){
			if(a[(i-1)*m+j]==k){
//				cout<<i<<' '<<j;
				if(i%2==0){
					cout<<i<<' '<<m-j+1;
				}else cout<<i<<' '<<j;
				return 0;
			}
		}
	}
	return 0;
}

