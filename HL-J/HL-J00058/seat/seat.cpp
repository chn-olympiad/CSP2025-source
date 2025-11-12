#include<bits/stdc++.h>
using namespace std;
long long m,n,arr[101],brr[101],crr[101],k=0,i;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	for( i=1;i<=m*n;i++){
		cin>>arr[i];
	}
	
	for( i=1;i<=m*n;i++){
		brr[i]=arr[i];
	}
	sort(arr+1,arr+i);
	
	for( i=1;i<=m*n;i++){
		if(brr[1]==arr[i]){
			k=i;
			k=abs(m*n-k+1);
		}
			
	}
	
		
	if(k<=n)
		cout<<1<<" ";
	else if(k%n==0)
		cout<<k/n<<" ";
	else
		cout<<k/n+1<<" ";
		
	if(k%n==0)
		cout<<n<<" ";
	else if((k/n+1)%2==1)
		cout<<k%n<<" ";
	else if((k/n+1)%2==0)
		cout<<m-(k%n)+1<<" ";
	return 0;

	
}
