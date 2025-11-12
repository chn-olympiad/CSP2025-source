#include <iostream>
#include <algorithm>
using namespace std;
int a[105],op,n,m,id;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1; i<=n*m; i++){
		cin>>a[i];
	}
	op=a[1];
	sort(a+1,a+n*m+1,cmp);
	for (int i=1; i<=m; i++){
		for (int j=1; j<=n; j++){
			if (a[(i-1)*m+j]==op){
				if (i%2==1){
					cout<<i<<" "<<j;
					return 0;
				}
				cout<<i<<" "<<n-j+1;
				return 0; 
			}
		}
	}
	return 0;
}
