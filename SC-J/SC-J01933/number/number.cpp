#include <bits/stdc++.h>
#define ll long long
using namespace std;

string s;
int num[15];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>s;
	ll len = s.size();
	for(int i = 0;i < len;i++){
		if(int('0') <= int(s[i]) && int(s[i]) <= int('9')){
			num[int(s[i]) - int('0')]++;
		}
	}
	for(int i = 9;i >= 0;i--){
		if(num[i]){
			for(int j = 1;j <= num[i];j++){
				cout<<i;
			}
		}
	}
	cout<<endl;
	return 0;
}

