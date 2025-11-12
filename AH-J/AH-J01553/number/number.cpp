#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
string s;
char c[1000005];
LL len=0;
bool cmp(const char x,const char y){return x>=y;}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	c[1]=' ';
	for(LL i=0;i<LL(s.size());i++)if(s[i]>='0'&&s[i]<='9')c[len++]=s[i];
	sort(c,c+len+1,cmp);
	cout<<c;
	return 0;
}
