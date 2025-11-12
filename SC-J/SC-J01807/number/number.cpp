#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
char b[10000000];
int c[10000000]; 
int main (){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int j=1;
	char n;
	while (cin >> n){
		int num=int(n);
		if (48<=num && num<=57){
			b[j]=n;
			j++;
		}
	}
	for (int qwe=1 ; qwe<j ; qwe++){
		if (b[qwe]=='0'){
			c[qwe]=0;
		}if (b[qwe]=='1'){
			c[qwe]=1;
		}if (b[qwe]=='2'){
			c[qwe]=2;
		}if (b[qwe]=='3'){
			c[qwe]=3;
		}if (b[qwe]=='4'){
			c[qwe]=4;
		}if (b[qwe]=='5'){
			c[qwe]=5;
		}if (b[qwe]=='6'){
			c[qwe]=6;
		}if (b[qwe]=='7'){
			c[qwe]=7;
		}if (b[qwe]=='8'){
			c[qwe]=8;
		}if (b[qwe]=='9'){
			c[qwe]=9;
		}
	}
	for (int k=1 ; k<j ; k++){
		int mx=0;
		for (int i=1 ; i<j ; i++){
				mx=max(mx,c[i]);
		}
		for (int l=1 ; l<j ; l++){
			if (mx==c[l]){
				 c[l]=0;
				 break;
			}
		}
		cout << mx;
	}
	return 0;
}