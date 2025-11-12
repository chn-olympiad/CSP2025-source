#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[15][15];
int ma[225];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int p=n*m;
	for(int i=1;i<=p;i++){
		scanf("%d",&ma[i]);
	}
	int R=ma[1];
	sort(ma+1,ma+p+1);
	/*for(int i=1;i<=p;i++){
		cout<<ma[i]<<' ';
	}*/
	int h=1,l=1;
	int whi=2;
	for(int i=p;i>=1;i--){
		a[h][l]=ma[i];
		if(whi%2==0){
			h++;
			if(h>n){
				h=n;
				l++;
				if(l>m)break;
				whi++;
			}
		}else{
			if(whi%2==1){
				h--;
				if(h<=0){
					h=1;
					l++;
					if(l>m)break;
					whi++;
				}
			}
		}
		
		
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==R){
				cout<<j<<' '<<i;
			}
		}
	}//All Check

	return 0;
}

