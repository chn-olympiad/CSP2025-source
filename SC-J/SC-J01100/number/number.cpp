#include <bits/stdc++.h>
using namespace std;
vector <int> s;
void in(){
	char ch = getchar();
	while((ch<'0'||ch>'9')&&(ch<'a'||ch>'z')) ch = getchar();
	while(('0'<=ch&&ch<='9')||('a'<=ch&&ch<='z')){
		if('0'<=ch&&ch<='9') s.push_back(ch&15);
		ch = getchar();
	}
	return ;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	in();
	sort(s.begin(),s.end());
	for(int i = s.size()-1 ; ~i ; i--) putchar(s[i]|'0');
	return 0;
}