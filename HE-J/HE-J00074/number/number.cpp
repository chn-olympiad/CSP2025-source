#include <bits/stdc++.h>
using namespace std;
int a[1000010],e;
string s;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') a[++e]=s[i]-'0';
	}
	sort(a+1,a+e+1,cmp);
	for(int i=1;i<=e;i++) cout <<a[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
