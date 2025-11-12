#include<bits/stdc++.h>
using namespace std;
int n,m,a[10005],b,c[10005],x,y,gr,p;
signed main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	b=a[1];
	sort(a+1,a+m*n+1);
	for(int i = n*m;i>=1;i--){
		if(b==a[i]){
			x=n*m-i+1;
		}
	}
	for(int i = 1;i<=m;i++){
		if(i%2==1){
			for(int j = 1;j<=n;j++){
				x--;
				if(x==0){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else{
			for(int j = n;j>=1;j--){
				x--;
				if(x==0){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
}
