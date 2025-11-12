#include <bits/stdc++.h>
using namespace std;
string a;
int n,m,k,s,t,l[1005];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> a;
	for(auto p : a){
		if(p>='0'&&p<='9'){
			l[int(p)-48]++;
		}
	}
	for(int i = 9;i>=0;i--){
		
		if(i == 0 && s == 0 && l[i]>=1){
			cout <<0;break;
		}
		if(l[i]>=1){
			for(int j = 1;j<=l[i];j++){
				cout << i;
			}s++;
		}
		
	}
	return 0;
}
