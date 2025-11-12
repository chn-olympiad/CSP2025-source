#include <bits/stdc++.h>
using namespace std;
string x;

int a, b, c, d, e, f, g, h, i, j;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	getline(cin, x);
	for (int z = 0; z < x.size(); z++){
		if (x[z] == '0'){
			a++;
		}
		else if (x[z] == '1'){
			b++;
		}
		else if (x[z] == '2'){
			c++;
		}
		else if (x[z] == '3'){
			d++;
		}
		else if (x[z] == '4'){
			e++;
		}
		else if (x[z] == '5'){
			f++;
		}
		else if (x[z] == '6'){
			g++;
		}
		else if (x[z] == '7'){
			h++;
		}
		else if (x[z] == '8'){
			i++;
		}
		else if (x[z] == '9'){
			j++;
		}
	}
	for (int z = 1; z <= j; z++){
		cout << 9;
	}
	
	for (int z = 1; z <= i; z++){
		cout << 8;
	}
	
	for (int z = 1; z <= h; z++){
		cout << 7;
	}
	
	for (int z = 1; z <= g; z++){
		cout << 6;
	}
	
	for (int z = 1; z <= f; z++){
		cout << 5;
	}
	
	for (int z = 1; z <= e; z++){
		cout << 4;
	}
	
	for (int z = 1; z <= d; z++){
		cout << 3;
	}
	
	for (int z = 1; z <= c; z++){
		cout << 2;
	}
	
	for (int z = 1; z <= b; z++){
		cout << 1;
	}
	
	for (int z = 1; z <= a; z++){
		cout << 0;
	}
	

	return 0;
} 
