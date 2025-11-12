#include<bits/stdc++.h>
using namespace std;

bool cmp(char a,char b){
	return a>b;
}

string s;
string ans;

void work(){
	cin>>s;
	for(int i=0;i<s.size();++i){
		if(s[i]>='0'&&s[i]<='9'){
			ans.push_back(s[i]);
		}
	}
	sort(ans.begin(),ans.end(),cmp);
	cout<<ans;
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	work();
	return 0;
}
