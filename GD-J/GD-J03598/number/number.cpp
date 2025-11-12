#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	vector<int> v;
	for (int i=0;i<s.size();i++){
		if (s[i]>='0' && s[i]<='9'){
			v.push_back(s[i]-'0');
		}
	}
	sort(v.begin(),v.end());
	string ans;
	int len=v.size()-1;
	for (int i=len;i>=0;i--){
		if (v[i]==0 && i==len){
			cout<<0;
			return 0;
		}
		ans+=v[i]+'0';
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
