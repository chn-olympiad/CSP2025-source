#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	cin >> n;
	long long a = n.size();
	long long p[a],x=0;
	for(int i = 0;i < a;i++){
		p[i] = 0;
	}
	for(int i = 0;i < a;i++){
		if(n[i] == '0' or n[i] == '1' or n[i] == '2' or n[i] == '3' or n[i] == '4' or n[i] == '5' or n[i] == '6' or n[i] == '7' or n[i] == '8' or n[i] == '9'){
		p[x] = n[i] - 48;
		x++;
		}
	}
	sort(p,p+x);
	for(int i = x-1;i > -1;i--){
		cout << p[i] ;
	}
	
	return 0;
}
