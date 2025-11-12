#include<bits/stdc++.h>
using namespace std;
int a[101],n,m,b[101],xh=1;
bool cmp(int a,int b){
	return a>b;
}
struct REN{
	int x,y;
} ren[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				ren[b[xh]].x=i;
				ren[b[xh]].y=j;
				xh++;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				ren[b[xh]].x=i;
				ren[b[xh]].y=j;
				xh++;
			}
		}
	}
	cout<<ren[a[1]].x<<" "<<ren[a[1]].y; 
	return 0;
}

