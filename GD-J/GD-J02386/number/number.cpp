#include <bits/stdc++.h>
using namespace std;
int d[1000008],l;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	getline(cin,s);
	int k=s.length();
	for(int i=0;i<k;i++){
		if(s[i]<='9'&&s[i]>='0'){
			d[l]=s[i]-'0';
			l++;
		}
	}
	sort(d,d+l);
	for(int i=l-1;i>=0;i--){
		cout<<d[i];
	}
	return 0;
}
