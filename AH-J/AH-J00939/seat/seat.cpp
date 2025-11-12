#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int n,m,x[105],a[15][15],t,cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>x[1];
	t=x[1];
	for (int i=2;i<=n*m;i++){
		cin>>x[i];
	}
	sort(x+1,x+1+n*m,greater<int>());
	for (int i=1;i<=m;i++){
		if (i%2==1){
			for (int j=1;j<=n;j++){
				a[j][i]=x[++cnt];
				if (x[cnt]==t){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else{
			for (int j=n;j>=1;j--){
				a[j][i]=x[++cnt];
				if (x[cnt]==t){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
