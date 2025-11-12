#include<bits/stdc++.h>
using namespace std;

string s,sn;
bool cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9') sn+=s[i];
	}
	sort(sn.begin(),sn.end(),cmp);
	cout<<sn;
	return 0;
}
