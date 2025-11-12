#include <bits/stdc++.h>
using namespace std;
int cnt;
char c[1000010];
bool cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size();
	if(len==1){
		cout<<s<<endl;
		return 0;
	}
	for(int i=0;i<len;i++){
		if('0'<=s[i]&&s[i]<='9'){
			char ss=s[i];
			c[cnt++]=ss;
		}
	}
	sort(c,c+cnt,cmp);
	for(int i=0;i<cnt;i++){
		cout<<c[i];
	}
	return 0;
}
