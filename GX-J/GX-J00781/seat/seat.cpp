#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a,a1;
	cin>>n>>m>>a>>a1;
	a=n*m;
	a1=100-a1;
	cout<<a1<<" "<<m;
	return 0;
}
