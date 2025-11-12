#include<bits/stdc++.h>
#define QAQ cout<<"QAQ";
using namespace std;
typedef long long ll;

const ll MAXN=2e5+5,inf=1e18,mod=1e9+7;
bool cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s,num;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			num.push_back(s[i]);
		}
	}
	sort(num.begin(),num.end(),cmp);
	cout<<num;
	return 0;
}
