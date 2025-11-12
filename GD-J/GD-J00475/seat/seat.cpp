#include <bits/stdc++.h>
using namespace std;
int n,m,a[15][15],c[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		scanf("%d",&c[i]);
	}
	int r=c[1];
	sort(c+1,c+n*m+1,cmp);
	int x=0;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				x++;
				a[i][j]=c[x]; 
				if(a[i][j]==r){
					cout<<i<<" "<<j<<'\n';
					return 0;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				x++;
				a[i][j]=c[x];
				if(a[i][j]==r){
					cout<<i<<" "<<j<<'\n';
					return 0;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

