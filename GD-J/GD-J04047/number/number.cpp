#include <bits/stdc++.h>
using namespace std;
string s;
int tal[1000001];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	s=" "+s;
	int idx=1;
	for(int i=1;i<=s.size();i++){
		if(s[i]>='0'&&s[i]<='9')tal[idx++]=(s[i]-'0');
	}
	sort(tal+1,tal+idx,cmp);
	for(int i=1;i<idx;i++){
		cout<<tal[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
