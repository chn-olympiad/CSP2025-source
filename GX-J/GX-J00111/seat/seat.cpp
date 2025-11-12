#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int n,m;
int a[N][N],b[N];
int cmp(int x,int c){
	return x>c;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	int xr=b[1],x1=1,r1=1,z=1;
	sort(b+1,b+1+n*m,cmp);
	for(int i=1;i<=n;i++){
		int ok=1;
		for(int j=1;j<=m;j++){
			if(z<=n*m){
				a[i][j]=b[z];
				z++;
			}
			else{
				ok=0;
				break;
			}
			if(a[i][j]==xr){
				x1=i;
				r1=j;
				ok=0;
				break;
			}
		}
		if(ok==0){
			break;
		}
		ok=1;
		i++;
		for(int j=m;j>=1;j--){
			if(z<=n*m){
				a[i][j]=b[z];
				z++;
			}
			else{
				ok=0;
				break;
			}
			if(a[i][j]==xr){
				x1=i;
				r1=j;
				ok=0;
				break;
			}
		}
		if(ok==0){
			break;
		}
	}
	cout<<x1<<" "<<r1;
	return 0;
}
