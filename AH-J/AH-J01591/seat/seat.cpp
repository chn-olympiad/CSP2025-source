#include <bits/stdc++.h>
using namespace std;
int n,m,cj[105],a[15][15],k,maxn[15],minn[15],ansm,ansn;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>cj[i];
	}
	k=cj[1];
	sort(cj+1,cj+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=cj[(i-1)*n+j];
		}
	}
	for(int i=1;i<=m;i++){
		maxn[i]=a[i][1];
		minn[i]=a[i][n];
	}
	for(int i=1;i<=m;i++){
		if(k<=maxn[i]&&k>=minn[i]){
			ansm=i;
			for(int j=1;j<=n;j++){
				if(a[i][j]==k){
					if(i%2==1){
						ansn=j;
					}else{
						ansn=n-j+1;
					}
				}
			}
		}
	}
	cout<<ansm<<' '<<ansn<<endl;
	return 0;
}
