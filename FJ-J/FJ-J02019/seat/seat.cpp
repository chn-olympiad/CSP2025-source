#include<bits/stdc++.h>
using namespace std;

int c[20][20];
int a[110];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int lr=a[1];
	sort(a+1,a+n*m+1,cmp);
	int now=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				c[j][i]=a[now];
				now++;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				c[j][i]=a[now];
				now++;
			}
		}
	}
	int ansx=-1,ansy=-1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(c[i][j]==lr){
				ansx=i;
				ansy=j;
			}
		}
	}
	cout<<ansy<<" "<<ansx;
	return 0;
}

