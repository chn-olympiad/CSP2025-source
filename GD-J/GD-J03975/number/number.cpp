#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int f[10];
string t;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	for(char k:t){
		if(k>='0'&&k<='9'){
			f[k-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<f[i];j++){
			cout<<i;
		}
	}
	return 0;
} 
