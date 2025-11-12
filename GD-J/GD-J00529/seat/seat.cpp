#include <bits/stdc++.h>
#define ll long long
#define N 105
using namespace std;

int n,m;
int a[N];
int num;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n*m;++i){
		cin >> a[i];
		if (a[i] >= a[1]) num++;
	} 
	
	int i = (num / n);
	int md = num % n;
	if (md) ++i;
	
	int j;
	if (i & 1) {
		if (md == 0) j = n;
		else j = md;
	}
	else{
		if (md == 0) j = 1;
		else j = n - md + 1;
	}
	cout << i << ' ' << j;
	
	
	
	
	return 0;
} 
