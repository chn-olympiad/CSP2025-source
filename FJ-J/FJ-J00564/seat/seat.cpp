#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[105];

//2 2
//99 100 97 98

int main(){

	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;++i)
		cin>>a[i];
	int t=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	int id=0;
	for(int i=1;i<=n*m;++i)
		if(a[i]==t){
			id=i;
			break;
		}
	int lie=0,hang=0,k=0;
	if(id%n==0)
		lie=id/n,k=n;
	else
		lie=id/n+1,k=id%n;
	if(lie%2==1)hang=k;
	else hang=n-k+1;	
	cout<<lie<<" "<<hang;
	
	return 0;
} 
