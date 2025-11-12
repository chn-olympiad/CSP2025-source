#include<bits/stdc++.h>
using namespace std;   
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int x=0,y=0;
	int a[1001][1001]={};
	cin>>n>>m;
	int b[1001]={};
	int l=n*m;
	cin>>b[0];
	int u=2;
	int s=0;
	s+=b[0];
	for(int i=1;i<l;i++){
		cin>>b[i];
	}
	sort(b,b+l);
	for(int i=l-1;i>=0;i--){
		a[x][y]=b[i];
		if(u%2==0){
			x++;
			if(x==n&&i>0){
				y++;
				x=n-1;
				u++;
			}
		}else{
			x--;
			if(x==0&&i>0){
				a[x][y]=b[i-1];
				i--;
				y++;
				u++;
				x=0;	
				
			}
		}
	}for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]==s){
				cout<<j+1<<" "<<i+1;
				return 0;
			}
		}
	}
	return 0;
	}
