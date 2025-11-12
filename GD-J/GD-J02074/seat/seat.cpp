#include<bits/stdc++.h>
using namespace std;
int n,m;
int zs;
int jl;
int a[1000];
int b[100][100];
int x=1,y=1,bh=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	zs=n*m;
	for(int i=1;i<=zs;i++){
		cin>>a[i];
	}
	jl=a[1];
	for(int i=1;i<=zs;i++){
		for(int j=1;j<=zs;j++){
			if(a[j]<a[j+1]){
				swap(a[j],a[j+1]);
			}
		} 
	} 
	int js=0;
	while(jl){
		b[x][y]=a[++js];		
		if(jl==a[js]){
			cout<<x<<" "<<y<<endl;
			return 0;
		}
		y+=bh;		
		if(y>n||y<1){
			if(y==0){
			y++;				
			}
			else if(y>n){
			y--;				
			}
			x++;
			bh*=-1;
		}
	}
	return 0;
} 
