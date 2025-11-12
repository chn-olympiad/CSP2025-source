#include<bits/stdc++.h>
using namespace std;
int a[100000][3],d=0,zb,n;
void f(int x,int y,int z,int D){
	if(x>n/2||y>n/2||z>n/2){
		return;
	}
	if(x+y+z==n){
		if(D>d){
			d=D;
			return;
		}
	}else{
		f(x+1,y,z,D+a[x+y+z+1][0]);
		f(x,y+1,z,D+a[x+y+z+1][1]);
		f(x,y,z+1,D+a[x+y+z+1][2]);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>zb;
	int c[zb];
	for(int h=0;h<zb;h++){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		}
		f(0,0,0,a[0][0]);
		f(0,0,0,a[0][1]);
		f(0,0,0,a[0][2]);
		c[h]=d;
		d=0; 
		for(int i=1;i<=n;i++){
			a[i][0]=0;
			a[i][1]=0;
			a[i][2]=0;
		}
	}
	for(int i=0;i<zb;i++){
		cout<<c[i]<<endl;
	}
	return 0;
}
