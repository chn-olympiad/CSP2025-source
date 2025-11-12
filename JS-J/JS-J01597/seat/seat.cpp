#include<bits/stdc++.h>
using namespace std;
int n,m,a[500];
int nb;
int js;
int njs;
int nbm,nbn;

int wz;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	nb=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==nb){
			wz=i;
			break;
		}
	}
	for(int i=1;i<=m;i++){
		js+=n;
		if(js>=wz){
			nbm=i;
			if(i%2){
				nbn=n-js+wz;
			}else nbn=js-wz+1;
			break;
		}
	}
	
	cout<<nbm<<' '<<nbn;
	return 0;
}
