#include<bits/stdc++.h>

using namespace std;

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	int n,m,fs,pm=1,tmp;
	cin >> n >> m >> fs;
	for (int i=1;i<n*m;i++){
		cin >> tmp;
		if (tmp>fs)pm++;
	}
	int hs=(pm-1)/n+1;
	cout << hs << " ";
	if (hs&1)cout << (pm-1)%n+1;
	else cout << n-((pm-1)%n);
	return 0;
}

