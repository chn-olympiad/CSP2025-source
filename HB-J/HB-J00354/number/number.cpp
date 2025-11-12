#include<bits/stdc++.h>
using namespace std;
int a[1000200];
string b[100200];
bool cmp(string q, string w){
	return q>w;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int s1=s.size();
	int cnt=0;
	for(int i=0;i<s1;i++){
		if(s[i]=='1' or s[i]=='2' or s[i]=='3' or s[i]=='4' or s[i]=='5' or s[i]=='6' or s[i]=='7' or s[i]=='8' or s[i]=='9' or s[i]=='0'){
			b[cnt]=s[i];
			cnt++;
		}
	}
	sort(b,b+cnt,cmp);
	for(int i=0;i<cnt;i++){
		cout<<b[i];
	}
	return 0;
}
