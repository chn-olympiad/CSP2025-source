#include<bits/stdc++.h>
#define LL long long
using namespace std;
string s;
LL a[100005], temp=0;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++) {
		if(s[i]>='0'&&s[i]<='9') {
			a[i]=s[i]-'0';
			temp++;
		}
	}
	sort(a,a+temp+1);
	for(int i=temp;i>0;i--){
		cout<<a[i];
	}
	return 0;
}

