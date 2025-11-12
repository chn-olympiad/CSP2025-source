#include<bits/stdc++.h>
using namespace std;
int cmp(int a1,int b1){return a1>b1;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[1001]={0},b[21][21]={0,0};
	cin>>n>>m;
	for(int i=1;i<=n*m;++i)cin>>a[i];
	int me=a[1],l=1,r=1,now;//location
	bool dis=false;//up(true) or down(flase)
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;++i){
		if(dis==false){
			if(l==n&&r<m){
				dis=true;
				b[l][r]=a[i];
				r++;
			}
			else {
				b[l][r]=a[i];
				l++;
			}
		}//down
		else {
			if(l==1&&r<m){
				dis=false;
				b[l][r]=a[i];
				r++;
			}
			else {
				b[l][r]=a[i];
				l--;
			}
		}//up
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(b[i][j]==me){cout<<j<<" "<<i;return 0;}
		}
	}
	return 0;
}
