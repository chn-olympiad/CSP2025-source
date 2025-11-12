#include<bits/stdc++.h>
using namespace std;

int a[20][20];
int p;
int n,m;
int b[200];
int s=0;
bool cmp(int x,int y){
	return x>y;
}
int x=1,y=1;

int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>b[i];
	
	p=b[1];
	sort(b+1,b+n*m+1,cmp);
	
	while(s<n*m){
		for(int i=1;i<=n;i++){
			a[i][y]=b[++s];
		}
		if(s==n*m) break;
		y++;
		for(int i=n;i>=1;i--){
			a[i][y]=b[++s];
		}
		y++;
	}
	
	
	for(int i=1;i<=n;i++){
		bool f=0;
		for(int j=1;j<=m;j++){
			if(a[i][j]==p){
				cout<<j<<" "<<i<<"\n";
				f=1;
				break;
			}
		}
		if(f) break;
	}
	
	return 0;
}
