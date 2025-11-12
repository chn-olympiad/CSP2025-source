/* UNDEBUGGED */
/* REDIRECTED */

#include<iostream>
#include<cstring>
#include<cctype>
#include<string>
#include<algorithm>
//#define debug CERTAINLY
using namespace std;

bool cmp(int a,int b) {
	return a>b;
}

const size_t MAXLEN=1e6;
int num[MAXLEN+5];//0-based (num[0] means 0)

int main() {
	//optimise i/o
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	//redirect i/o
	freopen("number.in","r",stdin);
#ifndef debug
	freopen("number.out","w",stdout);
#endif

	string s;
	cin>>s;
	size_t len=0;
	bool iszero=true;
	for(auto c:s) {
		if(isdigit(c))num[len++]=c-'0';
		if(c!='0')iszero=false;
	}
	sort(num,num+len,cmp);//ÉýÐò

	if(!iszero)for(size_t i=0; i<len; ++i)cout<<num[i];
	else cout<<'0';
	cout<<'\n';

	return 0;
}

