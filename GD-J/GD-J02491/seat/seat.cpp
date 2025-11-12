#include<bits/stdc++.h>
using namespace std;
const int N=11;

int a[N*N],b[N][N];
int n,m,t,ans;

bool cmp(int x,int y){
	return x>y;
}

signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		int x;
		cin>>x;
		if(i==1) t=x;
		a[i]=x;
	} 
	sort(a+1,a+1+n*m,cmp);
	int x=1,y=1,p=1,fx=0;
	while(p<=n*m){
		b[x][y]=a[p];
		if(fx==0){
			if(y+1<=n){
				y++;
			}else{
				x++;
				fx=1;
			}
		}else{
			if(y-1>=1){
				y--;
			}else{
				x++;
				fx=0;
			}
		}
		p++;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[j][i]==t){
				cout<<j<<" "<<i;
			}
		}
	}
	return 0; 
//	if(ans/n%2==0){
//		cout<<ans/n+1<<" "<<ans%n;
//	}else{
//		cout<<ans/n+1<<" "<<(n-(ans%n)+1)%n;
//	}
} 
