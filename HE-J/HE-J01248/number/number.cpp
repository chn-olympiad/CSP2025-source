#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int L=1e6+5;
string s;
int ls,a[L],cnt;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	ls=s.size();
	s=' '+s;
	for(int i=1;i<=ls;i+=1){
		if(s[i]>='0'&&s[i]<='9')a[++cnt]=s[i]-'0';
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i+=1){
		cout<<a[i];
	}
	cout<<endl;
	return 0;
}

