#include<bits/stdc++.h>
using namespace std;
int n,m,a[11][11],b[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	int myseat=b[1];
	sort(b+1,b+n*m+1);
	reverse(b+1,b+n*m+1);
	char fangxiang=1;
	int xuhao=1;
	for(int lie=1;lie<=m;lie++){
		if(fangxiang){
			for(int i=1;i<=n;i++){
				a[i][lie]=b[xuhao];
				if(myseat==b[xuhao]){
					cout<<lie<<' '<<i;
					return 0;
				}
				xuhao++;
			}
			fangxiang=0;
		}
		else{
			for(int i=n;i>=1;i--){
				a[i][lie]=b[xuhao];
				if(myseat==b[xuhao]){
					cout<<lie<<' '<<i;
					return 0;
				}
				xuhao++;
			}
			fangxiang=1;
		}
	}
	return 0;
}
