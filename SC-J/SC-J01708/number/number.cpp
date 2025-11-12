#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000010],cnt;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(unsigned i=0;i<s.size();i++){
		int v=s[i]-'0';
		if(v>=0&&v<=9)a[++cnt]=v;
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		cout<<a[i];
	}
	return 0;
}