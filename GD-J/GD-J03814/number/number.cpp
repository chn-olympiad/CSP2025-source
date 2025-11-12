#include<bits/stdc++.h>
using namespace std;
const int N=1e6+50;
char s[N];
vector<int> vec;
inline bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s);
	int len=strlen(s);
	for(int i=0;i<len;i++){
		if(s[i]>='0' && s[i]<='9') vec.push_back(s[i]-'0');
	}
	sort(vec.begin(),vec.end(),cmp);
	for(auto j:vec){
		putchar('0'+j);
	}
	return 0;
}
