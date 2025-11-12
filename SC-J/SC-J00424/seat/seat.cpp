#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1010],rr,mmap[1010][1010],x=1,y=1,k;//y,n行x,m列 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	rr=a[1];k=n*m;
	sort(a,a+1+n*m);
	for(x=1;x<=m;x++){
		for(int j=1;j<=n;j++){
			mmap[x][y]=a[k];
			y++;k--;
		}
		x++;y--;
		if(x>m) break;
		for(int j=1;j<=n;j++){
			mmap[x][y]=a[k];
			y--;k--;
		}
		y++;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(mmap[i][j]==rr){
				cout<<i<<" "<<j;return 0;
			}
		}
	}
	return 0;
}