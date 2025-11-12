#include<bits/stdc++.h>
using namespace std;

int a1[110],a[105],b[12][12];
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a1[i];
	}
	int le=a1[1];
	sort(a1+1,a1+m*n+1);
	for(int i=n*m;i>=1;i--){
		a[i]=a1[m*n-i+1];
	}
	int x=1,y=1,g=0,f=1,o=0;
	while(o!=m*n){
		g++; 
		o++;
		b[x][y]=a[g];
		if(x==n&&y%2==1){
			y++;
			f=-1;
		}
		else if(x==1&&y%2==0){
			y++;
			f=1;	
		}
		else{
			x+=f;
		}
		
	}
	for(int i1=1;i1<=n;i1++){
		for(int j1=1;j1<=m;j1++){
			if(b[i1][j1]==le){
				cout<<j1<<' '<<i1;
			}	
		}
	}
	return 0;
} 