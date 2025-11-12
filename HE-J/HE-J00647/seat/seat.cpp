#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int a[1001][1001],b[1010];
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	int R=b[1];
	sort(b+1,b+1+n*m);
	int c;
	for(int i=1;i<=n*m;i++){
		if(R==b[i]) c=i;
	}
	if(c/m%2==0) cout<<c/m<<' '<<n-c%m+1; 
	else cout<<c/m<<' '<<c%m+1;
	return 0;
}
