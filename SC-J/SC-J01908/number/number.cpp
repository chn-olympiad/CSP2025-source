#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
string ss;
int a[N] = {0};
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> ss;
	int siz = 0, ls =0;
	int j=1;
	while(ss[ls]!='\0'){
		ls++; 
		siz++;	
	} 
	for(int i=0; i<siz; i++){
		if(ss[i]>=48 && ss[i]<=57) {
			a[j] = int(ss[i]-48);
			j++;
		}
	}
	sort(a+1, a+j);
	for(int i=j-1; i>=1; i--){
		cout << a[i];
	}
	return 0;
}