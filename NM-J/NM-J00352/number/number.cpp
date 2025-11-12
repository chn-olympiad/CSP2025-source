#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin >> a;
    long long int b=a.length();
    string c;
    long long int x = 0;
    for(int i=0;i<b;i++){
    	if(a[i] == '0' || a[i] == '1'||a[i] == '2'||a[i] == '3'||a[i] == '4'||a[i] == '5'||a[i] == '6'||a[i] == '7'||a[i] == '8'||a[i] == '9'){
    		c += a[i];
    		x++;
		}
	}
	//int n = c;
	x = c.length();
	for(long long int i=0;i<x;i++){
    	if(c[i] == '9'){
    		cout << c[i];
		}
	}
	for(long long int i=0;i<x-1;i++){
    	if(c[i] == '8'){
    		cout << 8;
		}
	}
	for(long long int i=0;i<x;i++){
    	if(c[i] == '7'){
    		cout << c[i];
		}
	}
	for(long long int i=0;i<x;i++){
    	if(c[i] == '6'){
    		cout << c[i];
		}
	}
	for(long long int i=0;i<x;i++){
    	if(c[i] == '5'){
    		cout << c[i];
		}
	}
	for(long long int i=0;i<x;i++){
    	if(c[i] == '4'){
    		cout << c[i];
		}
	}
	for(long long int i=0;i<x;i++){
    	if(c[i] == '3'){
    		cout << c[i];
		}
	}
	for(long long int i=0;i<x;i++){
    	if(c[i] == '2'){
    		cout << c[i];
		}
	}
	for(long long int i=0;i<x;i++){
    	if(c[i] == '1'){
    		cout << c[i];
		}
	}
	for(long long int i=0;i<x;i++){
    	if(c[i] == '0'){
    		cout << c[i];
		}
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
