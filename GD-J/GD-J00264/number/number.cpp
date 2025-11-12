#include<iostream>
#include<cstring>
using namespace std;
const int si=1e6+10;
char s[si];
int ls,cnt[100];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s,ls=strlen(s);
	for(int i=0;i<ls;i++)
		if('0'<=s[i]&&s[i]<='9')
			++cnt[int(s[i]-'0')];
	for(int i=9;i>=0;i--)
		while(cnt[i]>0)--cnt[i],cout<<i;
	return 0;
}//NO!!!ÎÒµÄAK!!! 
