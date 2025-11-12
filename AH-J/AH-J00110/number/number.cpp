#include <bits/stdc++.h>
using namespace std;
string str;
char s[1000010];
int t=0;
bool cmp(char x,char y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(int i=0;i<str.size();i++){
		if(str[i]>='0' && str[i]<='9')
			s[++t]=str[i];
	}
	sort(s+1,s+t+1,cmp);
	for(int i=1;i<=t;i++)
		cout<<s[i];
	return 0;
}
