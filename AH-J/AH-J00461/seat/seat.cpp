#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],p,b[105][105],q;
bool cmp(int x,int y){
	if(x>y)
		return true;
	return false;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m*n;i++)
        cin>>a[i];
    p=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n;i++){
        b[i][1]=i;
    }
    for(int i=3;i<=m;i+=2){
        for(int j=1;j<=n;j++){
            b[j][i]=b[j][i-2]+2*n;
        }
    }
    for(int i=2;i<=m;i+=2)
        b[1][i]=i*n;
    for(int i=2;i<=m;i+=2){
        for(int j=2;j<=n;j++)
			b[j][i]=b[j-1][i]-1;
    }
    for(int i=1;i<=m*n;i++)
		if(a[i]==p)
			q=i;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==q)
				cout<<j<<" "<<i;
		}
	}
return 0;
}
