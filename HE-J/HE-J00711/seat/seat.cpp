#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[108];

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	int i;
	int c,p=0;
	int x=0,y=0;
	for(i=0;i<n*m;i++){
		cin>>a[i];
	}
	c=a[0];
	sort(a,a+n*m,cmp);
	for(i=0;i<n*m;i++){
		if(a[i]==c){
			p=i+1;
		}
	}
	y=p/n;
	if(p>y*n){
		y++;
	}
	if(y%2==1){
		x=p%n;
		if(x==0){
			x=n;
		}
	}else{
		x=p%n;
		if(x==0){
			x=n;
		}
		x=n+1-x;
	}
	cout<<y<<" "<<x;

	fclose(stdin);
	fclose(stdout);
	return 0;
}
