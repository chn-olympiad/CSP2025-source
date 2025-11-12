#include <bits/stdc++.h>
using namespace std;
int shuzi[10000010];
bool cmp(int x,int y){
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size(),cnt=0;
	for(int i=0;i<len;i++){
		char c=s[i];
		if((int)c<=57){
			shuzi[i]=(int)c-48;
			cnt++;
		}
	}
	sort(shuzi,shuzi+len,cmp);
	for(int i=0;i<cnt;i++) cout<<shuzi[i];
	return 0;
}