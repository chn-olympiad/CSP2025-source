#include <bits/stdc++.h>

using namespace std;
int n,m,a[200][200],b[10000];
int l,num=1;
bool k=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1; i<=n*m; i++) cin>>b[i];
	l=b[1];
	num=n*m;
	sort(b+1,b+1+n*m);
	for (int i=1; i<=m; i++){
		if (i%2==0){
			for (int j=n; j>=1; j--){
				a[j][i]=b[num];
				if (a[j][i]==l){
					cout<<i<<' '<<j;
					k=1;
					break;
				}
				num--;
			}
		}
		else{
			for (int j=1; j<=n; j++){
				a[j][i]=b[num];
				if (a[j][i]==l){
					cout<<i<<' '<<j;
					k=1;
					break;
				}
				num--;
			}
		}
		if (k) break;
	}
	return 0;
}
