#include<bits/stdc++.h>
using namespace std;
int num[1000500];
bool cmp(int &x,int &y) {
	return x>y;
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int t=1;
	cin>>s;
	int len=s.size();
	for(int i=0; i<len; i++) {
		if(s[i]>='0'&&s[i]<='9') {
			num[t]=s[i]-'0';
			t++;
		}
	}
	sort(num+1,num+1+t,cmp);
	for(int i=1; i<t; i++) {
		cout<<num[i];
	}
	return 0;
}
