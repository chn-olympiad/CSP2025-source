#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,Ai,c,r;
	cin>>n>>m;
	int a[n*m+2],s[n+2][m+2];
	cin>>a[1];
	Ai=a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a,a+n*m+1);
	for(int i=m;i>=0;i--){
		if(i%2==0){
			for(int j=n;j>=0;j--){
				if(a[i*j]==Ai){
					c=i,r=j;	
				}
				s[i][j]=a[i*j];
			}
		}else{
			for(int j=1;j<=n;j++){
				if(a[i*j]==Ai){
					c=i,r=j;	
				}
				s[i][j]=a[i*j];
			}
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
