#include <bits/stdc++.h>
using namespace std;
int m,n,i,j,a[11][11],r,b[101],f;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int k=0;k<m*n;k++){
		cin>>b[k];
	}
	r=b[0];
	sort(b,b+m*n);
	i=0,j=0,f=0;
	for(int k=m*n-1;k>=0;k--){
		a[i][j]=b[k];
		if(a[i][j]==r){
			cout<<j+1<<" "<<i+1;
			return 0;
		}
		if((i==n-1&&a[i-1][j]!=0)||i==0&&a[i+1][j]!=0){
			f++;
			f%=4;
			j++;
		}
		else if(f==1||f==3){
			f++;
			f%=4; 
			if(f==0){
				i++;
			}
			else{
				i--;
			}
		}
		else if(f==0){
			i++;
		}
		else if(f==2){
			i--;
		}
	}
	return 0;
}