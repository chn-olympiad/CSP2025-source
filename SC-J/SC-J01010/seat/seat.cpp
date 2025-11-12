#include<bits/stdc++.h>
using namespace std;

const int N=1e2+5;
int n,m,a[N],ed;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>ed;a[1]=ed;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+(n*m),cmp);
	int x=1,y=0;bool dt=0;
	for(int i=1;i<=n*m;i++){
		//cout<<"asdf";
		if(!dt){
			if(++y>n){
				x+=1;
				y-=1;
				dt=1;
			}
		}
		else{
			if(--y<1){
				x+=1;
				y+=1;
				dt=0;
			}
		}
		if(a[i]==ed){
			cout<<x<<" "<<y;
			break;
		}
	}
	return 0;
}