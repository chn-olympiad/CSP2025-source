#include<bits/stdc++.h>
using namespace std;
long long n,m,s[25][25],a[400];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	long long ans=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=0;i<=20;i++){
		for(int j=0;j<=20;j++){
			s[i][j]=-1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			s[i][j]=0;
		}
	}
	long long sum=n*m,x=1,y=1,w=1;
	while(sum--){
		s[x][y]=a[w];
		if(x==n){
			if(s[x-1][y]==0){
				x=x-1;
				y=y;
			}
			else{
				x=x;
				y=y+1;
			}
		}
		else if(x==1){
			if(s[x+1][y]==0){
				x=x+1;
				y=y;
			}
			else{
				x=x;
				y=y+1;
			}
		}
		else if(s[x-1][y]==0){
			x=x-1;
		}
		else if(s[x+1][y]==0){
			x=x+1;
		}
		w++;
	}
	long long ax,ay,h=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]==ans){
				ax=i,ay=j;
				h=1;
				break;
			}
		}
		if(h)break;
	}
	cout<<ay<<" "<<ax;
	return 0;
}
