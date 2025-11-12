#include<bits/stdc++.h>
using namespace std;
int a[110];
int n,m,p;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,1};
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	p=n*m;
	for(int i=1;i<=p;i++){
		cin>>a[i];
	}
	int ai=a[1];
	sort(a+1,a+1+p);
	int d=0,x=1,y=1;
	for(int i=p;i>0; ){
		for(int j=0;j<n;j++){
			if(a[i]==ai){
				cout<<y<<" "<<x;
				return 0;
			}
			x+=dx[d];
			y+=dy[d];
			i--;
		}
		x-=dx[d];
		y-=dy[d];
		d++;
		x+=dx[d];
		y+=dy[d];
		d++;
	}
}
