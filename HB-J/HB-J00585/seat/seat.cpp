##include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	//cin >> n >> m;
	int s[n*m]
	for(int i = 0; i < n * m; i++){
		cin >> s[i];
	}
	int x = s[0];
	sort(s, s + n * m);
	for(int i = n * m;i >= 1; i--){
		if(s[i] == x){
			int y = (i + 1) / n + 1;
			cout << y <<" ";
			if(y % 2 == 1){
				cout << i % n - 1;
				break;
				}
        }
        else{
		    cout << n - (i + 1) % n;
			break;
        }
    }
    return 0;
}

