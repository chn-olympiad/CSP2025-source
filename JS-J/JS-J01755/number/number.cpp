#include <bits/stdc++.h>
using namespace std;

string s;
int num[1000005],len;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	cin>>s;
	for (int i = 0;i<s.size();i++){
        if (s[i]>='0'&&s[i]<='9') num[len++] = s[i]-'0';
	}
	sort(num,num+len);
	for (int i = len-1;i>-1;i--) cout<<num[i];
	return 0;
}
