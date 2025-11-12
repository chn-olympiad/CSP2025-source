#include <bits/stdc++.h>
using namespace std;
string s;
int a[1002000],cnt;
bool cmp(int x,int y){
	return x>y;
}
int main(){//注意不是mian
	freopen("number.in","r",stdin);//不是freeopen
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i])) a[++cnt]=s[i]-'0';
	}
	sort(a+1,a+cnt+1,cmp);
	if(a[1]==0){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=cnt;i++){
		putchar(a[i]+48);
	}
	//上善若水吗,有.意思
	return 0;//注意返回值必须是0
}