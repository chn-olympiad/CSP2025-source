#include <bits/stdc++.h>
using namespace std;
int m,n;
int a[100005],b[10005],c[1005][1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int h=n*m;
	for(int i=1;i<=h;i++){
		cin>>a[i];
	}
	int ans=a[1];
	sort(a+1,a+h+1);
	c[1][1]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i%2==1&&i==1){
				if(j%2==1){
					c[i][j+1]=c[i][j]+2*n-(2*n-((n-i+1)*2-(i*2-1)));
				}
				if(j%2==0){
					c[i][j+1]=c[i][j]+(2*n-((n-i+1)*2-(i*2-1)));
				}
			}
			if(j%2==1&&i!=1){
				c[i][j]=c[i-1][j]+1;
			}
			if(j%2==0&&i!=1){
				c[i][j]=c[i-1][j]-1;
			}
		}
	}
	int x,y;
	for(int k=1;k<=h;k++){
		if(ans==a[k]){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					if(c[i][j]==h-k+1){
						x=j,y=i;
					}
				}
			}
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
