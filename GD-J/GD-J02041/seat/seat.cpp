#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],g,cc,b[11][11];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++) cin>>a[i];
	g=a[0];
	cc=n*m-1;
	sort(a,a+n*m);
	for(int i=0;i<n;i++){
		if(i%2==0){
			for(int j=0;j<m;j++){
				b[j][i]=a[cc];
				cc--;
			}
		}
		else{
			for(int j=m-1;j>=0;j--){
				b[j][i]=a[cc];
				cc--; 
			} 
		} 
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(b[i][j]==g){
				cout<<j+1<<" "<<i+1<<endl;
				return 0;
			}
		}
	}
}
