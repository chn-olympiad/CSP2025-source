#include<bits/stdc++.h>
using namespace std;
int a[11][11],b[102];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int r;
	for(int i=0;i<n*m;i++){
		cin>>b[i];
	}
	r=b[0];
	sort(b,b+m*n);
	int x=0,y=0;
	for(int i=n*m-1;i>=0;i--){
		a[x][y]=b[i];
		if(b[i]==r){
			cout<<y+1<<" "<<x+1<<endl;
			break;
		}
		if(x+1<=n-1&&a[x+1][y]==0){
			x=x+1;
		}
		else if((x-1<0||a[x-1][y]!=0)&&(x+1==n||a[x+1][y]!=0)){
			y=y+1;
		}
		else if(x-1>=0&&a[x-1][y]==0){
			x=x-1;
		}
	}
	return 0;
}
