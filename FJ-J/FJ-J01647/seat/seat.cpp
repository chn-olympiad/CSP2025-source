#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n,m,a[15][15],x,k=0,b[140];
cin>>n>>m;
for(int i=1;i<=n;i++){
	for(int j=1;j<=m;j++){
		cin>>a[i][j];
		b[++k]=a[i][j];
	}
}
x=a[1][1];
sort(b+1,b+n*m+1);
for(int i=n*m;i>=1;i--){
	if(b[i]==x){
		if((i%n)%2==0){
			cout<<i%n<<" "<<n-i/n+1;
		}
		else if(i%n!=0){
			cout<<i%n<<" "<<i/n;
		}
		else{
			cout<<n<<" "<<i/n;
		}
	}
}
return 0;
}
