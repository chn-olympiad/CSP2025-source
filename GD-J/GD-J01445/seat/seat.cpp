#include <bits/stdc++.h>
using namespace std;
const long long N=1e2+7;
int n,m,a[17][17],b[N],cnt,t,x;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>x;
	b[1]=x;
	for (int i=2;i<=n*m;i++){
		cin>>b[i];
	}
	sort(b+1,b+n*m+1);
	for (int i=1;i<=m;i++){
		if (t==0){
			for (int j=1;j<=n;j++){
				a[j][i]=b[n*m-cnt];
				cnt++;
			}
			t=1;
		}
		else{
			for (int j=n;j>=1;j--){
				a[j][i]=b[n*m-cnt];
				cnt++;
			}
			t=0;
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if(a[i][j]==x){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
