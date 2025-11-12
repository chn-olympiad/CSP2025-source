#include<bits/stdc++.h>
using namespace std;
long long arr[100000005],hl[10][10];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,r; 
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>arr[i];
	}
	r=arr[1];	
	for(int i=1;i<=n*m;i++){
		if(arr[i+1]>arr[i]){
			arr[i+1]=arr[i];
		}	
	}		
	for(int i=1;i<=n*m;i++){
		arr[i]=hl[n][m];
		n++;
		m++;
		if(r==arr[i]){
			cout<<hl[n][m];
			return 0;	
		}
			
	}
	n--;
	m--;
	return 0;
}	

