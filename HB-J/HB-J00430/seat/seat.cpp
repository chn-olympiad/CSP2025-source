#include <bits/stdc++.h>
using namespace std;
int n,m,nmr;
int a[105];
int cmp(int x,int y){
	return x>y;
}	
int main()
{
	freopen("seat.in","w",stdin);
	freopen("seat.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	nmr=a[1];
	sort(a+1,a+m*n+1,cmp);
	for(int i=1;i<=m*n;i++){
		if(a[i]==nmr){
			nmr=i;
			break;
		}
	}
	if(nmr%n!=0){
		cout<<nmr/n+1<<" ";
		if((nmr/n+1)%2==1){
			cout<<nmr%n;
		}	
		else {
			cout<<n-nmr%n+1;
		}	
	}
	else {
		cout<<nmr/n<<" ";
		if(nmr/n%2!=0){
			cout<<n;
		}	
		else {
			cout<<1;
		}	
	}				
	return 0;	
}	
	

