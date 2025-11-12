#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e2+5;
int a[MAXN];

int main (){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int paiming=1;
	for (int i=1;i<=n*m;i++){
		cin >> a[i];
		if (a[1]<a[i]){
			paiming++;
		}
	}
	int c,r;
	c=paiming/n+1;
	if (c%2==0){
		r=n-paiming%n+1;
	}else {
		r=paiming%n;
	}
	cout << c << " " << r;
	return 0;
}
