#include <bits/stdc++.h>
using namespace std;

int a[10000];
int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	cin >> s;
	int n = 10000;
	int an = 0;
	int min = 10000;
	int sum = 0;
	if(n > 1){
		for(int i=0;i<n;i++){
			if(s[i] == 0 || s[i] == 1 || s[i] == 2 || s[i] == 3 || s[i] == 4 || s[i] == 5 || s[i] == 6 || s[i] == 7 || s[i] == 8 || s[i] == 9){
				a[i] = s[i];
				an++;
			}
		}
	}
	int aa[an+5];
	int nn = 0;
	for(int i=0;i<an;i++){
		for(int j=0;j<an;j++){
			if(a[j] < min){
				min = a[j];
				aa[nn] = a[j];
				nn++;
			}	
		}
	}
	for(int i=0;i<an;i++){
		sum += aa[i]*pow(10,i);
	}
	
	cout << sum << endl;
	
	return 0;
}
