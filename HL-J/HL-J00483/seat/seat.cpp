#include <bits/stdc++.h>
using namespace std;

const int N=110;
int n,m,k=1;
int a[N];
int c[N][N];

bool cmp(int x,int y){
	if(x>y) return true;
	else return false;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int a1=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2!=0){
			for(int j=1;j<=n;j++){
				c[j][i]=a[k++];
			}
		}else{
			for(int j=n;j>=1;j--){
				c[j][i]=a[k++];
			}
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(c[i][j]==a1)
				cout<<j<<' '<<i;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
