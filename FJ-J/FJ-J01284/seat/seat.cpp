#include<bits/stdc++.h>
using namespace std;
int n,m,r;
int a[1005]; 
int v[1005][1005];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=1,k=1;
	v[x][y]=a[k];
	//if(a[k]==r)printf("1 1\n");
	//else{
		while(x>=1 and x<=n and y>=1 and y<=m and k<=n*m){
			
			while(x<n and y<=m and k<n*m){
				x++,k++;
				
				v[x][y]=a[k];
			}
			if(x==n){
				y++;
				k++;
				v[x][y]=a[k];
			}
			
			while(x>1 and y<=m and k<n*m){
				x--,k++;
				
				v[x][y]=a[k];
			}
			if(x==1){
				y++;
				k++;
				v[x][y]=a[k];
			}
		}
	//}
	int c,d;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(v[i][j]==r){
				c=i,d=j;
				
			}
		}
	}
	printf("%d %d\n",d,c);
	//cout<<d<<" "<<c<<"\n";
	return 0;
}
