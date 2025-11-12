#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int lct[n+5][m+5],a[n*m+5],ans,ax[]={1,0,-1,0},ay[]={0,1,0,-1},t=0,rec=0,x=0,y=1;
	memset(lct,-1,sizeof(lct));
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			lct[i][j]=0;
		}
	}
	for (int i=1;i<=n*m;i++) cin>>a[i];
	ans=a[1];
	sort(a+1,a+n*m+1);
	reverse(a+1,a+n*m+1);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			while (lct[x+ax[t]][y+ay[t]]!=0){
				t=(t+1)%4;
			}
			x+=ax[t],y+=ay[t];
			lct[x][y]=a[++rec];
			if (t==1 || t==3){
				t=(t+1)%4;
			}
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if (ans==lct[i][j]){
				cout<<j<<" "<<i;
				break;
			}
		}
	}
	return 0;
} 
