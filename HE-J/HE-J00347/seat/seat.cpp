#include <bits/stdc++.h>
using namespace std;
int a[150];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x=1,y=1,s;
	bool f=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;++i)
		cin>>a[i];
	s=a[1];
	for(int i=1;i<=n*m;++i){
		for(int q=2;q<=n*m;++q){
			if(a[q]>a[q-1])
				swap(a[q],a[q-1]);
		}
	}
	for(int i=1;i<=n*m;++i){
		if(a[i]==s){
			cout<<y<<' '<<x;
			break;
		}
		if(f&&x!=n)
			x++;
		else if(!f&&x!=1)
			x--;
		else if(x==n){
			y++;
			f=0;
		}
		else if(x==1){
			y++;
			f=1;
		}
	}
	return 0;
}
