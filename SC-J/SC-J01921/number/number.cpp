#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
vector<int>v;
int cmp(int a,int b){
	return a>b;
} 
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	for(int i = 0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			int p = s[i]-'0';
			v.push_back(p);
		}
	}
	sort(v.begin(),v.end(),cmp);
	for(int i = 0;i<v.size();i++){
		if(v[i]==0){
			cout<<v[i];
			break;
		}
		cout<<v[i]; 
	}
	return 0;
}
