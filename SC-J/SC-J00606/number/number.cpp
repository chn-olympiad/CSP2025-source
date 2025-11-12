#include<bits/stdc++.h>
using namespace std;
string s;
int cnt,num[100001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0') num[++cnt]=s[i]-'0';
	}
	sort(num+1,num+cnt+1);
	for(int i=cnt;i>=1;i--) printf("%d",num[i]);
	return 0;
}