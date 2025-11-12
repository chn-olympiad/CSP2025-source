#include<bits/stdc++.h>
using namespace std;
bool cmp(char x,char y){
	if(x!='0'&&y!='0')return x>y;
	else if(x!='0'&&y=='0')return x;
	else return y;
}
int main(){
	freopen(number.in,"r",std.in);
	freopen(number.out,"w",std.out);
	string s;
	cin>>s;
	string a;
	int h=0;
	for(int i=0;i<s.size();i++){
		if('1'<=s[i]&&s[i]<='0'){
			h++;
			a[i]=s[i];
		}
	}
	sort(a,a+a.size(),cmp);
	for(int i=0;i<h;i++)cout<<a[i];
	return 0;
}
