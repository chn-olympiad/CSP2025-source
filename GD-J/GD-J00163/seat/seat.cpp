#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e6 + 10;

int n,m,a[N],ans,ansx,ansy;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);	
	cin >> n >> m;
	ans=1;
	for (int i=1;i<=n*m;i++){
		cin >> a[i];
		if (a[i]>a[1]) ans++;
	}
	ansx=(ans-1)/n+1;
	ansy=(ans-1)%n+1;
	if ((ansx&1)^1) ansy=n-ansy+1;
	cout << ansx << " " << ansy << "\n";
} 
