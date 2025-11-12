#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[100],n,m,b[10][10],c,d,e;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	d=a[1];
	c=n*m;
	sort(a+1,a+c+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(j%2==1){
				e=(j-1)*n+i;
			}
			else{
				e=(j-1)*n+(n-i)+1;
			}
			if(d==a[e]){
				cout<<i<<" "<<j;
				break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
