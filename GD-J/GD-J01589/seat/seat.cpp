#include<bits/stdc++.h>
using namespace std;
int m,n,dz;
int sz[110];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	cin>>sz[1];
	dz=sz[1];
	for(int i=2;i<=n*m;i++){
		cin>>sz[i];
	}
	sort(sz+1,sz+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(sz[i]==dz){
			int im=i%m,im1=i/m;
			if(im==0){
				cout<<im1<<" "<<m;
				return 0;
			}
			im1++;
			if(im1%2==0){
				cout<<im1<<" "<<m-im+1;
				return 0;
			}
			cout<<im1<<" "<<im;
			return 0;
		}
	}
	return 0;
}
