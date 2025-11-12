#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
int a[15];
bool check(char a){
	int a1=a-'0';
	return a1>=0&&a1<=9;
}
int main(){
	string s;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(check(s[i]))a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		if(a[i]>0){
			for(int j=1;j<=a[i];j++)cout<<i;
		}
	}
	return 0;
}
