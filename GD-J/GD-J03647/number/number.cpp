#include<iostream>
using namespace std;
int t[10];
int n;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;n=s.length();
	for(int i=0;i<n;i++) if('0'<=s[i]&&s[i]<='9') t[s[i]-'0']++;
	for(int i=9;i>=0;i--) while(t[i]){
		cout<<i; t[i]--;
	}
	return 0;
} 
