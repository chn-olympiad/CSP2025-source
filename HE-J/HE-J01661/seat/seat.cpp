#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int a, b, c, H, R, g, G = 0/*, J = 0, J2 = 0*/;
	cin >> a >> b;
	g = b - 1;
	c = a * b;
	int h[c];
	for(int i = 0; i < c; i++){
		cin >> H;
		h[i] = H;
	}
	R = h[0];
	sort(h+0, h+c);
	if(a == 1 && b == 1){
		cout << "1 1" << endl;
	}
	int A, B;
	int L[A][B];
	for(int i = 0; i < c; i++){
		if(i % 2 == 0){
			L[A+1][B+0];
		}
		else if(i % 2 != 0){
			L[A-1][B+0];
		}
		G++;
		if(G == a){
			L[A+0][B+1];
		}
		if(h[i] == R){
			cout << L[A][B] << endl;
		}
	}
	/*int A, B;
	int L[a][b];
	for(int i = 1; i <= a; i++){
		for(int j = 1; j <= b; j++){
			if(R == h[i-1]){
				A = i;
				B = 0+j;
				J++;
			}
			if(R == h[i-1] && J == a){
				A = i+1;
				B = 2 - i + 1;
			}
		}
	}
	cout << A << " " << B;*/
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
