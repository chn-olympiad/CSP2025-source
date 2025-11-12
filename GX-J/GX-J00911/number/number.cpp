#include<bits/stdc++.h>
using namespace std ;
int s;
int main(){

	cin >> s ;
	for (int i = 10 ; i > 0 ; i * 10){
	if (s < 10){
		cout << s ;
	break ;
		}
	else {
		cout <<  s % i << " ";
	if (s < 10){
		cout << s ;
		break ;
			}
		}
	}

	return 0 ;
}
