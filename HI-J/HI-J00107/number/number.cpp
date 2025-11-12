#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char a[100005];int num=0;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size();
	if(len==1){
		cout<<s;
		return 0;
	}
	for(int i=0; i<=len; i++) {
		if(s[i]>='0'&&s[i]<='9') {
			a[num]=s[i];
			num++;
		}
	}
	sort(a+0,a+1+num);
	for(int i=num;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}

