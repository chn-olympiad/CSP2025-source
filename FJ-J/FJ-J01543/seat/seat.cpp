#include <bits/stdc++.h>
using namespace std;
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int t=a[1],t_id=0;
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==t){
			t_id=n*m-i+1;
			break;
		}
	}
	int x=(t_id-1)/n+1;
	cout << x << " ";
	int y=(t_id-1)%(2*n)+1;
	if(y>n) y=2*n-y+1;
	cout << y;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
