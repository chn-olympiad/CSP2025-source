#include <bits/stdc++.h>
using namespace std;
string s;
long long a[1000010],t;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	s+='*';
	for(int i=0;s[i]!='*';i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[t]=s[i]-'0';
			t++;
		}
	}
	sort(a,a+t,cmp);
	for(int i=0;i<t;i++){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}