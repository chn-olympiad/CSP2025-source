#include<bits./stdc++.h>
using namespace std;

int c(int e,int d){
	int p=1;
	int q=1;
	for (int x=e-d+1;x<=e;x++)
	{
		p=p*x;
	}
	for (int y=1 ;y<=d;y++)
	{
		q=q*y;
	}
	int z=p/q;
	return z;
}

int main(){
	int n;
	int a[5004];
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	cin >> n;
	int w=0;
	for (int i=0;i<n;i++){
		cin >> a[i];
	}
	for (int j=3;j<=n;++j){
		w+=c(n,j);

	}
	
	cout << w;
	return 0;
}