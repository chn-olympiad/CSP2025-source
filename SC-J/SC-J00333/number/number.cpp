#include<bits/stdc++.h>
using namespace std;
string s;
bool cmp(char b,char c){
	return b>c;
} 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	char a[1000001];
	int n=0;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			n++;
			a[n]=s[i];
		}
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		cout<<a[i]; 
	}
	return 0;
} 