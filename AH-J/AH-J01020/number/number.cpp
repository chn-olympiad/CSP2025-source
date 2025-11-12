#include<bits/stdc++.h>
using namespace std;
vector<int>v;
string s;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for (int i=0;i<len;i++){
		char ch=s[i];
		if (ch>='0' && ch<='9'){
			v.push_back(ch-'0');
		}
	}
	int size=v.size();
	sort(v.begin(),v.end(),cmp);
	for (int i=0;i<size;i++){
		cout<<v[i];
	}
	return 0;
}
