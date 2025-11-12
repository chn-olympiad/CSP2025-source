#include <bits/stdc++.h>
using namespace std;
int a[1000001],cnt=0;

bool bijiao(int n,int m){
	return n>m;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int c=s.size();
	for(int i=0;i<c;++i){
		if(s[i]-'0'<'a'-'0'){
			a[i]=s[i]-'0';
			cnt++;
		}
	}
	sort(a+0,a+0+c,bijiao);
	for(int i=0;i<cnt;++i){
		cout << a[i];
	}
	return 0;
}
