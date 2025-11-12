#include <bits/stdc++.h>

using namespace std;

int a[1000005]; 

int main ()
{
	//freopen("number.in", "r", stdin);
	//freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int i=0, j=1;
	while ( i <= s.size() ){
		if ( int(s[i]) >= 48 && int(s[i]) <= 59){
			a[j] = (int)s[i] - 48;
			j++;
		}
		i++;
	}
	j--;
	
	//
	//for (int t = 1; t<=j; t++) cout << a[t];
	//cout << endl;
	
	int jj = j;
	for (int q=1; q<=jj; q++){
		int maxa = a[1], ma=1;
		for (int x=2; x<=j; x++){
			if (a[x] > maxa){
				maxa = a[x];
				ma = x;
				//cout << '/'<< ma;
			}
		}
		cout << maxa;
		for (int y=ma; y<j; y++){
			a[y] = a[y+1];
		} //cout <<" |"; for (int t=1; t<=j;t++)cout<< a[t];
		//cout << endl;
		j--;
	}
	return 0;
}
