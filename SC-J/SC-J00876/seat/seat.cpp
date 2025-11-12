#include <bits/stdc++.h>
using namespace std;
long long int n,m,b,x,y;
int a[1000001],a1[1001][1001],c[1000001];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	long long int he=n*m;
	for(int i=1;i<=he;i++){
		cin>>a[i];
		b=a[1];
	}
	x=1,y=1;
	int she=m/2,yu=m%2;
	int cnt=0;
	sort(a+1,a+n*m+1);
	for(int i=1;i<=he;i++){
		c[i]=a[n*m-i+1];
	}
	if(n==1&&m==1){
		cout<<1<<" "<<1;
	}else if(n==1&&m<=10){
		for(int i=1;i<=he;i++){
			if(c[i]==b){
				cout<<i<<" "<<1;
			}
		}
	}else if(n<=10&&m==1){
		for(int i=1;i<=he;i++){
			if(c[i]==b){
				cout<<1<<" "<<i;
			}
		}
	}else if(m==2){
		for(int j=1;j<=n;j++){
			a1[1][j]=c[++cnt];
		}a1[2][n]=c[++cnt];
		for(int j=n-1;j>=1;j--){
			a1[2][j]=c[++cnt];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(a1[i][j]==b){
					cout<<i<<" "<<j;
				}
			}
		}	
	}else{
		if(yu!=0){
			a1[1][1]=c[++cnt];
			for(int i=1;i<=she;i++){
				for(int j=2;j<=n;j++){
					a1[x][j]=c[++cnt];
				}a1[++x][n]=c[++cnt];
				for(int j=n-1;j>=1;j--){
					a1[x][j]=c[++cnt];
				}a1[++x][1]=c[++cnt];
			}for(int i=2;i<=n;i++){
				a1[x][i]=c[++cnt];
			}
		}else{
			a1[1][1]=c[++cnt];
			for(int i=1;i<=she;i++){
				for(int j=2;j<=n;j++){
					a1[x][j]=c[++cnt];
					}a1[++x][n]=c[++cnt];
				for(int j=n-1;j>=1;j--){
					a1[x][j]=c[++cnt];
				}if(i<she)	a1[++x][1]=c[++cnt];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(a1[i][j]==b){
					cout<<i<<" "<<j;
				}
			}
		}	
	}
	return 0;
}