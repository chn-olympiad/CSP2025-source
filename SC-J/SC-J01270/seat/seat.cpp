#include <bits/stdc++.h>
using namespace std;
int n,m,s,c;
bool g(int x,int y){
	return x>y;	}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int a[n*m+10];
	for (int i=1;i<=n*m;i++)
		cin>>a[i];
	s=a[1];
	sort(a+1,a+m*n+1,g);
	
	for(int i=1;i<=n*m;i++)
		if(a[i]==s){
			c=i;
			}	
		if (c%n==0)
			if(c/n%2==1){
				cout<<c/n<<" "<<n;
				return 0;
			}
			else{
				cout<<c/n<<" "<<1;	
				return 0;
			}
	if((c/n+1)%2==1)
			cout<<c/n+1<<" "<<c%n;
	else 
		cout<<c/n+1<<" "<<n-c%n+1;
	return 0;
}