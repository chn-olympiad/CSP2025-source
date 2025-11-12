#include<bits/stdc++.h>
using namespace std;

string s,res;
int a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i = 0;i < s.size();++i){
		if(s[i]>=48&&s[i]<=57){
			a[s[i]-48]++;
		}
	}
	for(int i = 9;i >=0 ;i--){
		if(a[i]){
			for(int j = 1;j <= a[i];++j){
				char c = i+'0';
				res += c;
			}
		}
	}
	cout<<res;
	return 0;
}