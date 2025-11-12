#include<iostream>
using namespace std;
int n,m,a[200],cnt=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1])cnt++;
	}
	int x=cnt/m;
	if(x*m!=cnt)x++;
	cout<<x<<' ';
	if(x%2==1)cout<<cnt-(x-1)*m;
	else cout<<m-cnt+(x-1)*m+1;
}
