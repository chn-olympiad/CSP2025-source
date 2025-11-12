#include<bits/stdc++.h>
using namespace std;
long long a[15][15],b[105],n,m,x=1,y=1;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	long long t=b[1];
	sort(b+1,b+m*n+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(y%2==1){
			a[x][y]=b[i];
			if(b[i]==t){
				cout<<y<<" "<<x;
				break;
			}
			x++;
			if(x>n){
				x--;
				y++;
				if(y>m){
					y--;
				}
			}
			continue;
		}
		if(y%2==0){
			a[x][y]=b[i];
			if(b[i]==t){
				cout<<y<<" "<<x;
				break;
			}
			x--;
			if(x==0){
				x++;
				y++;
				if(y>m){
					y--;
				}
			}
			continue;
		}
	}
}

