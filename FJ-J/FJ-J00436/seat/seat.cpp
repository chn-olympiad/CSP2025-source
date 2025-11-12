#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int r = 0;
	for(int i = 1;i<=n*m;i++){
		cin>>a[i];
	}
	r = a[1];
	sort(a+1,a+n*m+1);
	int k = 0;
	for(int i = 1;i<=n*m;i++)if(a[i] == r)k = i;
	k = n*m-k+1;
	int lie = (k-1)/n+1;
	int hang = k-(lie-1)*n;
	if(hang == 0)hang = n; 
	if(lie%2 == 0)hang = n-hang+1;
	cout<<lie<<" "<<hang; 
}
