#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],b[15][15],R,x=0,y=0,fx=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>R;
	a[0]=R;
	for(int i=1;i<n*m;i++) cin>>a[i];
	sort(a,a+n*m);
	reverse(a,a+n*m);
	for(int i=0;i<n*m;i++){
		/*if(a[i]==R){
			cout<<y+1<<' '<<x+1;
			break;
		}*/
		b[x][y]=a[i];
		if(x>=n-1&&fx==1){
			y++;
			fx=-1;
		}else if(x<=0&&fx==-1){
			y++;
			fx=1;
		}else{
			x+=fx;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(b[i][j]==R){	
				cout<<j+1<<' '<<i+1;
				return 0;
			}
		}
	}
	return 0;
}
