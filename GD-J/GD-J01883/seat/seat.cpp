#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],s[55][55];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m/2;i++){
		int temp=a[i];
		a[i]=a[n*m-i+1];
		a[n*m-i+1]=temp;
	}
	int i=1,j=1;
	while(true){
		if(i%2!=0){
			j++;
			if(j>n){
				j--;
				i++;
				s[i][j]=a[i*n-j+1];
			}else{
				s[i][j]=a[(i-1)*n+j];
			}
			if(s[i][j]==x){
				cout<<i<<" "<<j;
				return 0;
			}
		}else{
			j--;
			if(j<1){
				j++;
				i++;
				s[i][j]=a[(i-1)*n+j];
			}else{
				s[i][j]=a[i*n-j+1];
			}
			if(s[i][j]==x){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
} 
