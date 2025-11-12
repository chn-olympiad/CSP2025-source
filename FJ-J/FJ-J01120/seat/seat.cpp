#include<bits/stdc++.h>
using namespace std;
int a[110],n,m,x=1,y=1,b,s;
bool c[20][20];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	s=m*n;
	for(int i=1;i<=s;i++){
		cin>>a[i];
		if(i==1){
			b=a[i];
		}
	}
	sort(a+1,a+s+1,cmp);
	c[1][1]=1;
	for(int i=1;i<=s;i++){
		if(a[i]==b){
			cout<<y<<" "<<x;
			break;
		}
		else if(c[x+1][y]==0 && x+1<=n){
			c[x+1][y]=1;
			x++;
			//cout<<x<<" "<<y<<endl;
		}
		else if(c[x-1][y]==0 && x-1>=1){
			c[x-1][y]=1;
			x--;
			//cout<<x<<" "<<y<<endl;
		}
		else if(c[x][y+1]==0 && y+1<=m){
			c[x][y+1]=1;
			y++;
			//cout<<x<<" "<<y<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
