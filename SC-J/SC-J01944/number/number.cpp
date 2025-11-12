#include<bits/stdc++.h>
using namespace std;
bool check(char a) {
	if(a-'0'>=0&&a-'0'<=10)
		return true;
	return false;
}
long long t[10],cnt=0;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,ans;
	cin>>s;
	for(int i=0; i<s.size(); i++) {
		if(check((char)s[i])) {
			t[s[i]-'0']++;
			cnt++;
		}
	}
	//for(int i=1;i<=9;i++)
	//	cout<<t[i]<<" ";
	//cout<<endl;
	int p=9;
	while(1) {
		if(p<0)
			break;
		if(t[p]==0) {
			//cout<<"pos:"<<p<<endl;
			p--;
			continue;
		}
		//cout<<p<<endl;
		t[p]--;
		//ans*=10;
		//ans+=p;
		cout<<p;
	}
	return 0;
}