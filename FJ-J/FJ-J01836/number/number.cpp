#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
string s;
int siz,len,a[MAXN];

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++siz]=s[i]-'0';
		}
	}
	sort(a+1,a+siz+1,greater<int>());
	for(int i=1;i<=siz;i++){
		printf("%d",a[i]);
	}
	return 0;
}
