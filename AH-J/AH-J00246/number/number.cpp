#include<bits/stdc++.h>
using namespace std;
string s;
bool comp(char a,char b){
	return a>b;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	cin>>s;
	//1. 提取出 s 当中的所有数字字符，排序。
	int n=s.size();
	string t="";
	for(int i=0;i<n;i++){
		if(s[i]>='0' && s[i]<='9'){
			t+=s[i];
		}
	}
	sort(t.begin(),t.end(),comp);
	cout<<t;
	return 0; 
}
