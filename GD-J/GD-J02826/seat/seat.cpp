#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>m>>n;
	int k=0;
	int a[15][15]={};
	int b[105]={};
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
		if(i==1)k=b[i];
	}
	
	sort(b+1,b+n*m+1);
	
	
	int cnt=0;
	/*
	int x=1,y=1;
	while(y<m){
		while(x<n){
			cnt++;
			a[x][y]=b[cnt];
			if(a[x][y]==k){
				cout<<x<<' '<<y;
				return 0;
			}
			x++;
		}
		
		
		
		cnt++;
		x=n;
		a[x][y]=b[cnt];
		if(a[x][y]==k){
			cout<<x<<' '<<y;
			return 0;
		}
		y++;
		while(x>1){
			cnt++;
			a[x][y]=b[cnt];
			if(a[x][y]==k){
				cout<<x<<' '<<y;
				return 0;
			}
			x--;
		}
		cnt++;
		x=1;
		a[x][y]=b[cnt];
		if(a[x][y]==k){
			cout<<x<<' '<<y;
			return 0;
		}
		y++;
		
		while(x<n){
			cnt++;
			a[x][y]=b[cnt];
			x++; 
		}
		cnt++;
		x=1;
		a[x][y]=b[cnt];
		if(a[x][y]==k){
			cout<<x<<' '<<y;
			return 0;
		}
		y++;
		
		
	}
	
	*/
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=b[cnt];
			
			if(a[i][j]==k){
				if(n<=2)
					cout<<n-j+1<<' '<<i;
				else cout<<n-j+1<<' '<<n-i;
			}
			cnt++;
		}
	}
	return 0;
}

