#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
string s;
int num[maxn];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int k = 0;
	for(int i = 0; i < s.size(); i++){
		if(isdigit(s[i])){
			num[k] = s[i]-'0';
			k++;
		}
	}
	for(int i = 0; i < k; i++){
		for(int j = i+1; j < k; j++){
			if(num[i] < num[j]) swap(num[i], num[j]);
		}
	}
	for(int i = 0; i < k; i++) cout << num[i];
	return 0;
}