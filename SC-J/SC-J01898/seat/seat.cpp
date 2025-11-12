#include<bits/stdc++.h>
using namespace std;
int n,m,r;
int a[1000],d[1000][1000];;
bool cmp(int a,int b){
	return a>b;
}
bool down;
void went(int x,int y,int i){
	if(x<n&&down==true){
		x++;
		down=true;
	}else if(down==true){
		x--;
		y++;
		down=false;
	}
	if(x>=0&&down==false){
		x--;
		down=false;
	}else if(down==false){
		x++;
		y++;
		down=true;
	}
	d[x][y]=a[i];
	if(d[x][y]==r){
		cout<<x+1<<" "<<y+1;
		exit(0);
	}
	went(x,y,i+1);
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int i;
	for(i=0;i<n*m;i++)cin>>a[i];
	r=a[0];
	sort(a,a+n*m,cmp);
	went(0,0,0);
	return 0;
}