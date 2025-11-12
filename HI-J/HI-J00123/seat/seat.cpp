#include <bits/stdc++.h>
using namespace std;
char n[1000005];
char m[1000005];
char a[1000005];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	for(int i = 1; i <= 2; i++){
		cin >> n[i];
		cin >> m[i];
	}
	for(int i = 1; i <= n[i] * m[i]; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n[i] * m[i]; i++){
		if(a[i] < a[i+1]){
			a[i] == a[i+2];
			
		}
		
	}
	return 0;
}

