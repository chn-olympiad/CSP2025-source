#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("./cspj/down/number/number2.in","r",stdin);
	//freopen("./cspj/down/number/number2.ans","w",stdout);
	queue<char> q;
	string s;
	cin>>s;
	char a[1000005];
	int num=0,maxn=0,ans=0;
	for (int i=0;i<s.length();i++){
		if (s[i]>='0'&&s[i]<='9'){
			num++;
			q.push(s[i]);}
	}
	for (int i=0;i<num;i++){
		a[i]=q.front();
		q.pop();}
	sort(a,a+num);
 	for (int i=num-1;i>=0;i--) cout<<a[i];
 	return 0;
}
