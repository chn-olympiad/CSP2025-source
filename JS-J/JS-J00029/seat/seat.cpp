#include<bits/stdc++.h>
using namespace std;
int a[15][15];
int b[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
   int m,n,x=1,y=1;
   cin>>m>>n;
   for(int i=1;i<=m*n;i++){
	   cin>>b[i];
    }
    int c;
    c=b[1];
    sort(b+1,b+1+m*n,cmp);
    for(int i=1;i<m*n;i++){
		if(b[i]==c){
			cout<<y<<" "<<x;
			}
		if(x==m&&y%2==1){
			y=y+1;
		}else{
			if(x==1&&y%2==0){
				y=y+1;
			}else{
				if(y%2==1){
					x++;
				}else x--;
		     }
		}
	}
	/*for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			
		}
	}*/
return 0;
}
