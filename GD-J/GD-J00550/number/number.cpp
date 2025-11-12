#include <bits/stdc++.h>
using namespace std;
string a;
const int N=2e6+5;
int b[N];
int main(){
	freopen("number","r",stdin);
	freopen("number","w",stdout);
	cin >> a;
	int cnt=1;
	for(int i=0;i<a.size();i++){
		if(a[i]>=48&&a[i]<=48+9){
			b[cnt]=a[i]-48;
			cnt++;
		}
	}
	sort(b+1,b+cnt);
	for(int i=cnt-1;i>0;i--){
		cout << b[i];
	}
} 
