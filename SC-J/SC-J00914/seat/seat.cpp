#include<bits/stdc++.h>
using namespace std;
int a[105][105];
int b[10005];
bool c(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	r=b[1];
	sort(b+1,b+n*m+1,c);
	a[1][1]=b[1];
	int p=2;
	int xi=1,yi=1;//列,行 
	for(int i=1;i<=n*m;i++){
		if(a[xi+1][yi]==0&&xi+1<=m){
			xi+=1;
			if(b[p]==r){
				cout<<yi<<" "<<xi;
				return 0;
			}
			a[xi][yi]=b[p];
			p++;
			continue;
		}
		else if(a[xi-1][yi]==0&&xi-1>=1){
			xi-=1;
			if(b[p]==r){
				cout<<yi<<" "<<xi;
				return 0;
			}
			a[xi][yi]=b[p];
			p++;
			continue;
		}
		else if(a[xi][yi+1]==0&&yi+1<=n){
			yi+=1;
			if(b[p]==r){
				cout<<yi<<" "<<xi;
				return 0;
			}
			a[xi][yi] = b[p];
			p++;
			continue;
		}
	}
	return 0;
}