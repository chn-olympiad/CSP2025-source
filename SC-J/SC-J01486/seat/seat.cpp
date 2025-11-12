#include<bits/stdc++.h>
using namespace std;
int n,m,c,r;
int a[105],score,b[11][11],cnt=1;
bool cmp(int x,int y){
	return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int nm=n*m;
    for(int i=1;i<=nm;i++){
    	cin>>a[i];
	}
	score=a[1];
	sort(a+1,a+nm+1,cmp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			a[cnt++]=b[i][j];
			if(i<=n&&j==m) {j--; 
			}
			if(b[i][j]==score){
				c=j;
				r=i;
				break;
			}
		}
	}
	cout<<c<<" "<<r;
	return 0;
}