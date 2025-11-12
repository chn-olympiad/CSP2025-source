#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;
string instring;
char numout[1000000+5];
int k=0;
int main(){
	freopen ("number.in", "r", stdin);
	freopen ("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >>instring;
	for (unsigned int i=0; i<=(instring.size()); ++i){
		if (instring[i]>='0' && instring [i]<='9'){
			numout[k]=instring[i];
			k++;
		}
	}
	sort (numout, numout+k);
	for (int i=k; i>=0; --i){
		cout <<numout[i];
	}
	return 0;
}
