#include<bits/stdc++.h>
using namespace std;
string s;
struct nd{
	int val;
	char str;
}ss[1000003];
bool cmp(nd a,nd b){
	return a.val>b.val;
}
int main(void){
	//freopen
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int cnt=0;
	int t=s.size();
	for(int i=0;i<t;++i){
		if(s[i]>='0'&&s[i]<='9'){
			ss[cnt].str=s[i];
			ss[cnt].val=s[i]-'0';
			++cnt;
		}
	}
	sort(ss,ss+cnt,cmp);
	for(int i=0;i<cnt;++i){
		cout<<ss[i].str;
	}
	return 0;
}
//08:55 T1 ok
