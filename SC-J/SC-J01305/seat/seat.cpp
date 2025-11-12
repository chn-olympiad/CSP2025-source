#include<bits/stdc++.h>
using namespace std;
int a[15][15],b[100];
int n,m,nm,k;
int pm;

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	nm=n*m;
	for(int i=1;i<=nm;i++){
		cin>>b[i];
	}
	k=b[1];
	sort(b+1,b+1+nm,cmp);
	for(int i=1;i<=nm;i++){
		if(b[i]==k){
			pm=i;
			break;
		}
	}
	int h,l;
	for(int i=1;i<=m;i++){
		if(i%2==1)
			for(int j=1;j<=n;j++){
				if((i-1)*n+j==pm){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		else{
			for(int j=n;j>=1;j--){
				if((i-1)*n+(j-n+1)==pm){
					cout<<i<<' '<<j;
					return 0;
				}
			}			
		}
	}
	return 0;
}