#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
string s;
int num[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int siz = s.size();
	for(int i = 0;i < siz;i++){
		if(s[i] >= '0' && s[i] <= '9'){
			num[s[i] - '0']++;
		}
	}
	for(int i = 9;i >= 0;i--){
		while(num[i]--){
			cout<<i;
		}
	}
	return 0;
}
