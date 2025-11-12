#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int R=a[1];
	int r=m/(100-R),c=m%(100-R);
	if(c==0) c=1;
	cout<<c<<" "<<r;
	return 0;
}
