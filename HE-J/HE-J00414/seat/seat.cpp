#include<bits/stdc++.h>
using namespace std;
int n,m,x[10010],k=1,a[30][30];
bool cmp(int x,int y){
	return x>y;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>x[i];
	int y=x[1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i%2==1){
				a[j][i]=k;
				k++;
			}else{
				a[m-j+1][i]=k;
				k++;
			}
		}
	} 
	sort(x+1,x+(n*m)+1,cmp);
	int z;
	for(int i=1;i<=n*m;i++){
		if(x[i]==y)z=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[j][i]==z){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
