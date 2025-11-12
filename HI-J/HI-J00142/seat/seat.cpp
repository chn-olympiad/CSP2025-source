#include <bits/stdc++.h>
using namespace std;

int a[105];
int b[15][15];
bool cmp(int u,int v){
	return u>v;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	int c=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[c]);
			c++;
		}
	}
	int re=a[1];
	c--;
	sort(a+1,a+c+1,cmp);
	int i=1;
	for(int y=1;y<=m;y++){
		if(y%2==1){
			for(int x=1;x<=n;x++){
				if(a[i]==re){
					cout<<y<<" "<<x;
				}
				b[x][y]=a[i];
				i++;
			}
		}else{
			for(int x=n;x>=1;x--){
				if(a[i]==re){
					cout<<x<<" "<<y;
				}
				b[x][y]=a[i];
				i++;
			}
		}
	}
	return 0;
}
