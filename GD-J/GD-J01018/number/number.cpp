#include<bits/stdc++.h>
#define ll long long
#define y1 y114514
using namespace std;
bool cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w".stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	string t;
	cin>>t;
	string s;
	for(int i=0;i<t.size();i++){
		if(t[i]>='0'&&t[i]<='9')s+=t[i];
	}
	sort(s.begin(),s.end(),cmp);
	cout<<s;
	return 0;
}
/*
I AK CSP-J! 
luogu: zbl2012
//freopen("number.in","r",stdin);
//freopen("number.out","w".stdout);
*/
