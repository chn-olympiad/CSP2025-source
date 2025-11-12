#include<bits/stdc++.h>
using namespace std;
string s;
int sum[1000005],len;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0;i < s.length();i++){
		if(s[i] >= '0' && s[i] <= '9'){
			sum[++len] = s[i] - '0';
		}
	}
	sort(sum+1,sum+len+1);
	for(int i = len;i >= 1;i--) cout<< sum[i]; 
	return 0;
}
