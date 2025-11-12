#include<bits/stdc++.h>
using namespace std;
int a[11][11];
int b[101];
bool cmp(int x,int y){
	return x>y;
}

int main(){
	preoper("seat.in","r",stdin);
	preoper("seat.out","w",stdout);
	int n,m,x;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
		if(i==1){
			x=b[i];
		}
	}
	int j=1;
	sort(b+1,b+1+n*m,cmp);
	for(int i=1,u=1;i<=n&&u<=n*m;i++){
		if(j==1){
			for(j=1;j<=m;j++){
				if(b[u]==x){
					cout<<i<<" "<<j;
					i=n+1;
					break;
				}
				u++;
			}
		}else{
			for(j=m;j>=1;j--){
				if(b[u]==x){
					cout<<i<<" "<<j;
					i=n+1;
					break;
			}
			u++;
		}
	}
    }
	return 0;
}
