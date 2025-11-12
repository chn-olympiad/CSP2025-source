#include<bits/stdc++.h>
using namespace std;
long long n,a[1000010];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	int f=0;
	for(int i=0;i<s.size();i++){
		if((s[i]-'0')<=9 && (s[i]-'0')>=0){
			a[++f]=s[i]-'0';
		}
	}
	sort(a+1,a+f+1);
	for(int i=f;i>=1;i--)cout<<a[i];
	return 0;
}
