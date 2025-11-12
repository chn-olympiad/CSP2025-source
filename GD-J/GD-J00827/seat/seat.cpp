#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a0,pr=1;
	int n,m,a[15][15]={0}; 
	cin>>n>>m;
	cin>>a0;
	for(int i=2;i<=n*m;i++){
		int j;
		cin>>j;
		if(j>a0){
			pr++;
		}
	}
	int sx=0;//1为向上，0为向下 
	int xx=1,yy=1;
	for(int i=1;i<pr;i++){
		if(sx==0){
			if(yy+1<=n){
				yy++;
			}else{
				xx++;
				sx=1;
			}
		}else{
			if(yy-1>=1){
				yy--;
			}else{
				xx++;
				sx=0;
			}
		}
	}
	cout<<xx<<' '<<yy;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
