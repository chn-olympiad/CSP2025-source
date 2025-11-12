#include<bits/stdc++.h>
using namespace std;

int n,m,a[15][15],b[105],c,r,x;

bool cmp(int z,int y){
	return z>y;
}

int main(){
	freopen("seat3.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	x=b[1];
	sort(b+1,b+1+n*m,cmp);
	int k=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++,k++){
				a[j][i]=b[k];
				if(x==b[k]) cout<<i<<' '<<j;
			}
		}else{
			for(int j=n;j>=1;j--,k++){
				a[j][i]=b[k];
				if(x==b[k]) cout<<i<<' '<<j;
			}
		}
	} 
	
	return 0;
} 
