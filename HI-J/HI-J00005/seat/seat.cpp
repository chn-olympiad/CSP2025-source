#include<bits/stdc++.h>
using namespace std;
int seat[13][13],mark[105],x=1,y=1,p,num;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a1;
	cin>>n>>m>>a1;
	for(int i=1;i<n*m;i++){
		cin>>mark[i];
	}
	num=n*m;
	
	mark[103]=a1;
	bool daoxu=0;
	sort(mark+1,mark+1+n*m);
	for(int i=1;i<=n*m;i++){
		seat[x][y]=mark[i-1];
		if(seat[x][y]==a1){
			break;
		}
		if(daoxu){
			y--;
			if(y<1){
				y=1;
				x++;
				daoxu=0;
			}
		}
		else{
			y++;
			if(y>n){
				y--;
				x++;
				daoxu=1;
			}
		}
		
	}
	cout<<x<<" "<<y;
	fclose(stdin);
	fclose(stdout); 
	return 0;
} 
