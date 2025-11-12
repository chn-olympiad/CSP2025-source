#include<bits/stdc++.h>
using namespace std;
int a[100][100],b[150],n,m,f,r,mc;
void zw(int n,int m){
	int fl=1,s=0;
	for(int i=1;i<=m;i++){
		if(fl==1){
			for(int j=1;j<=n;j++){
				s+=1;
				a[i][j]=s;
			}
		}
		else if(fl==0){
			for(int j=n;j>=1;j--){
				s+=1;
				a[i][j]=s;
			}
		}
		if(fl==1){
			fl=0;
		}
		else if(fl==0){
			fl=1;
		} 
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	zw(n,m);
	for(int i=1;i<=n*m;i++){
		cin>>f;
		if(i==1) r=f;
		b[i]=f;
	}
	sort(b+1,b+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(b[i]==r) mc=m*n+1-i;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]==mc) cout<<i<<" "<<j;
		}
	}
	return 0;
} 