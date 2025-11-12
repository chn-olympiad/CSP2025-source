#include <bits/stdc++.h>
using namespace std;
int zw[11][11],cj[121];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,cnt=0,acj=0;
	cin>>n>>m;
	cnt=n*m;
	for(int i=1;i<=cnt;i++) cin>>cj[i];
	acj=cj[1];
	sort(cj+1,cj+1+cnt);
	int k=1;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			zw[i][j]=cj[k];
			k++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(zw[i][j]==acj){
				cout<<j<<" "<<i;
				break;
			}
		}
	}
	return 0;
}