#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a[1010],l=0;
	string s;
	getline(cin,s);
	int m=s.size();
	for(int i=0;i<=m;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[l]=(int)s[i]-48;
			l++;
		}
	}
	sort(a,a+l);
	for(int i=l-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
