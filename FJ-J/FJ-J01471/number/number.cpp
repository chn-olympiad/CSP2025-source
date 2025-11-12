#include <bits/stdc++.h>
using namespace std;
string s;
string n;
int sum[1086];
int vi=1;
bool check(char a){
	int num=a-'0';
	if(num>=0&&num<=9) return 1;
	return 0;
}
int number(char a){
	return a-'0';
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(check(s[i])){
			sum[vi]=number(s[i]);
			vi++;
		}
	sort(sum+1,sum+1+vi);
	for(int i=vi;i>=2;i--){
		cout<<sum[i];
	}
	cout<<n;
	return 0;
}
