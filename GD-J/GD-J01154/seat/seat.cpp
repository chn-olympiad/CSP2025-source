#include<bits/stdc++.h>
using namespace std;
int a[20][20];
int f[200];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>f[i];
	}
	int w=f[1];
	sort(f+1,f+1+n*m,greater<int>());
	int x=1,y=1;
	int idx=0;
	while(1){
		while(x<=n){
			a[x][y]=f[++idx];
			if(a[x][y]==w) {
				cout<<y<<' '<<x;
				return 0;
			}
			x++;
		}
		x--;
		y++;
		while(x>=1){
			a[x][y]=f[++idx];
			if(a[x][y]==w) {
				cout<<y<<' '<<x;
				return 0;
			}
			x--;
		}
		x++;
		y++;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
