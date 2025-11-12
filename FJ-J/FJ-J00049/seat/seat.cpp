#include<bits/stdc++.h>
using namespace std;
long long n,m,val,id,a[305];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	val=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==val){
			id=n*m+1-i;
			int lie=(id-1)/n+1,hang;
			if(lie&1)hang=(id-1)%n+1;
			else hang=n-(id-1)%n;
			printf("%ld %ld",lie,hang);
			break;
		}
	}
	return 0;
}

