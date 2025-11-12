#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
int a[MAXN];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int tit=0;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i] &&s[i]<='9'){
			tit++;
			a[tit]=s[i]-'0';
		}
	}
	sort(a+1,a+1+tit);
	for(int i=tit;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
