#include<bits/stdc++.h>
using namespace std;
int m,n,c;
int a[105][105],b[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=m*n;i++){
		cin>>b[i];
	}
	c=b[1];
	sort(b+1,b+m*n+1);
	int x=1,y=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			y++;
			if(c==b[n*m-y+1]){
				cout<<i<<" "<<x;
				return 0;
			}
			if(j==m&&i%2==1||j==1&&i%2==0){
				continue;
			}
			if(i%2==1){
				x++;
			}else{
				x-=1;
			}	
		}
		
		
	}
	
	
	
	
	return 0;
}
