#include<bits/stdc++.h>
using namespace std;
int a[102],n,m,sx,s[11][11],e=1,y=1,x=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
		for(int i=1;i<=n*m;i++) cin>>a[i];
		sx=a[1];
		sort(a+1,a+1+(n*m));
		int j=(n*m)+1;
		for(y=1;y<=m;e++){
			if(x==n){
				while(x>=1){
				
				s[x][y]=a[j];
//				cout<<s[x][y]<<x<<" "<<y;
				x--;
				j--;
			}	
			j++;
			x++;
			}
			else if(x==1){
			while(x<=n){
				
				s[x][y]=a[j];
//				cout<<s[x][y]<<x<<" "<<y;
				x++;
				j--;
			  }
			j++;
			x--;	
			}
		    if(e==n) {
			y++;
			e=0;	
			}
		}
		for(int x=1;x<=n;x++){
			for(int y=1;y<=m;y++){
				if(s[x][y]==sx){
					cout<<y<<' '<<x;
					return 0;
				}
			}
		
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
