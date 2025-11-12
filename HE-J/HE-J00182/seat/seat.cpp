#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int N=100+100;
int b[N];
int n,m;
bool c(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>b[i];
	int r=b[1];
	sort(b+1,b+n*m,c);
	for(int i=1;i<=n*m;i++)
		if(r==b[i]){
			r=i;
			break;	
		}
		
	int x=r/n;
	int y=r-x*n;
	if(x==0){
		cout<< 1 << " " << y;
		return 0;
	}
	for(int i=1;i<=m;i++){
		if(x==i){
			if(y==0){
				if(x%2==0)
						cout<< x << " " << 1;				
				else
					cout<< x << " " << n;
				return 0;
			}
			for(int j=1;j<=n;j++){
				if(y==j){
					if((x+1)%2==0)
						cout<< x+1 << " " << n-y+1;			
					else
						cout<< x+1 << " " << y;
					return 0;
				}
			}
		}
	}
	return 0;
}
