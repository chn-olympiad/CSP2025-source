#include<bits/stdc++.h>
using namespace std;
long long a[109],n,m,x,c,j;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	x=n*m;
	cin>>a[1];
	c=a[1];
	for(int i=2;i<=x;i++){
		cin>>a[i];
	}
	sort(a+1,a+x+1);
	for(int i=x;i>=1;i--){
		j=x-i+1;
		if(a[i]==c){
			if(j%n==0){
				if((j/n)%2==0)cout<<j/n<<' '<<'1';
				else cout<<j/n<<' '<<n;
			}
			else {
				if((j/n+1)%2==0)cout<<j/n+1<<' '<<n-j%n+1;
				else cout<<j/n+1<<' '<<j%n;
			}
			return 0;
		}
	}
}
