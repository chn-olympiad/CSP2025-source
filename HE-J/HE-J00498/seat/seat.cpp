#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y;
};
int n,m,ji=0,jii;
int a[105];
node b[105];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				ji++;
				b[ji].x=i;
				b[ji].y=j;
			}
		}else{
			for(int j=m;j>=1;j--){
				ji++;
				b[ji].x=i;
				b[ji].y=j;
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	jii=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==jii){
			cout<<b[i].x<<" "<<b[i].y;
		}
	}
	return 0;
} 
