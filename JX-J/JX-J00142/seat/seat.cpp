#include<bits/stdc++.h>
using namespace std;
int t;
int x=1,y=1;
int a[11][11];
int s[120];
bool f[11][11];
int n,m;
bool ff(int x,int y){
	return x>=1 && x<=n && y>=1 && y<=m && f[x][y]==0;
}
void ans(int x,int y,int i){
	if(s[i]==t){
	  printf("%d %d",y,x);
	  return;	
	}
    if(ff(x,y)==1){
		f[x][y]=1;
		a[x][y]=s[i];
	    if(x==1 && f[x+1][y]==1){
			//cout<<"1"<<endl;
			y++;
		}
	    else if(x==1 && f[x+1][y]==0){
			//cout<<"2"<<endl;
			x++;
		 }
	    else if(x==n && f[x-1][y]==1){
			//cout<<"3"<<endl;
			y++;
		 }
	    else if(x==n && f[x-1][y]==0){
			//cout<<"4"<<endl;
			x--;
		}
	    else{
			//cout<<"5"<<endl;
			if(f[x-1][y]==1) x++;
			else if(f[x+1][y]==1) x--;
		}
		ans(x,y,i-1);
	}else return; 
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++){
	    scanf("%d",&s[i]);
	    if(i==1) t=s[i];	
	}
	sort(s+1,s+n*m+1);
	ans(x,y,n*m);
	return 0;
}
