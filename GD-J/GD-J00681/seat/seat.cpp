#include<bits/stdc++.h>
using namespace std;
int n,m,p,b[1000][1000],l=1;
struct tt{
	int x,i;
}a[1011010];
bool c(tt a,tt b){
	return a.x>b.x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].x;
		a[i].i=i; 
	}
	sort(a+1,a+1+n*m,c);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(p==0){
				b[j][i]=a[l].x;
				if(a[l].i==1)cout<<i<<" "<<j,exit(0);
			}else{
				b[n-j+1][i]=a[l].x;	
				if(a[l].i==1)cout<<i<<" "<<n-j+1,exit(0);
			}
			l++;
		}
		p=!p;
	}
}
