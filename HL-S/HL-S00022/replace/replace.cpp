#include<bits/stdc++.h>
using namespace std;
long long ans;
int _substr(string s,string t){
	bool isSuccessful;
	for(int i=0;i<t.size()-s.size();i++){
		isSuccessful=1;
		for(int j=0;j<s.size();j++){
			if(s[j]!=t[i+j]){
				isSuccessful=0;
			}
		}
		if(isSuccessful){
			return i;
		}
	}
	return 1145141919;
}
void replace(string s1,string s2,string t1,string t2){
	int i;
	while(i<t1.size()){
		i=_substr(s1,t1);
		if(t1.substr(0,i)+s2+t1.substr(i+s2.size())==t2){
			ans++;
			replace(s1,s2,t1.substr(i+s2.size()),t2.substr(i+s2.size()));
		}
	}
}
int main(){
    //freopen("replace.in","r",stdin);
    //freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    vector<pair<string,string>> s(n),t(q);
    for(int i=0;i<n;i++){
    	cin>>s[i].first>>s[i].second;
	}
	for(int i=0;i<q;i++){
		cin>>t[i].first>>t[i].second;
	}
	for(int i=0;i<q;i++){
		ans=0;
		for(int j=0;j<n;j++){
			replace(s[j].first,s[j].second,t[i].first,t[i].second);
		}
		cout<<ans<<'\n';
	}
    return 0;
}
