#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number3.in" , "r" , stdin);
	freopen("number3.out" , "w" , stdout);
	string n;
	char N[1000010];
	cin>>n;
	int j = 0;
	for(int i = 0 ; i < n.length() ; i++){
		if(n[i] - '0' <= 9 && n[i] - '0' >= 0){
			N[++j] = n[i] - '0';
		}
	}
	sort(N , N + j + 1);
	for(int i = j ; i >= 1 ; --i){
		cout<<N[i] + '0' - 48;
	}
	return 0;
}
