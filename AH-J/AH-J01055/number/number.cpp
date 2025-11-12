#include<bits/stdc++.h>
using namespace std;
string s;
vector<int> v;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int ss=s.size();
	for(int i=0;i<ss;i++){
		if(s[i]-'0'>=0 and s[i]-'0'<=9){
			v.push_back(s[i]-'0');
		}
	}
	sort(v.begin(),v.end());
	int vv=v.size();
	for(int i=vv-1;i>=0;i--){
		cout<<v[i];
	}
	return 0;
}
