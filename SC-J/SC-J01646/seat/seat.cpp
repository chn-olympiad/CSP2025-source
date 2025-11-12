#include<bits/stdc++.h>
using namespace std;
const int N=1e3; 

int n,m;
int a[N],name,bi=0;

bool cmp(int ax,int by){
	return ax>by;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	a[0]=-100;
	name=a[1];
	sort(a+1,a+1+n*m,cmp);
	int x=0,y=1;
	while(1){
		y=0;
		x++;
		for(int i=1;i<=n;i++){
			y++;
			bi++;
			if(a[bi]==name){
				cout<<x<<" "<<y;
				exit(0);
			}
		}
		x++;
		y=n+1;
		for(int i=1;i<=n;i++){
			y--;
			bi++;
			if(a[bi]==name){
				cout<<x<<" "<<y;
				exit(0);
			}
		}
	}
	return 0;
} 
