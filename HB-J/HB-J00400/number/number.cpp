#include <bits/stdc++.h>
using namespace std;
const int N=1e6+1;
int a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(char i:s){
		if(s[i]>='0'&&s[i]<='9'){
			a[i-'0']++;
		}
	}	
	for(int i=100001;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			cout<<i;
		}
	}
	return 0;
}
