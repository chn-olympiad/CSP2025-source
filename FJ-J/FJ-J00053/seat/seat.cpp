#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int m,n,a[1000],b,c,d[100][100],e,f;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	b=a[1];
	sort(a+1,a+m*n+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==b){
			c=i;
			break;
		}
	}
	for(int i=1;i<=m;i++){
		if(e%2==0){
			for(int j=1;j<=n;j++){
				d[i][j]=++f;
				if(f==c){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				d[i][j]=++f;
				if(f==c){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
		e++;
		if(d[m][1]==c){
			cout<<m<<' '<<1;
			break;
		}if(d[m][n]==c){
			cout<<m<<' '<<n;
			break;
		}
		
	}
	return 0;
}
