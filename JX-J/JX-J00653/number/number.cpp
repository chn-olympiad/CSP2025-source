#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define LL long long
int n;
string s;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    vector<int>sz;
    int si=s.size();
    for(int i=0;i<si;i++){
		if(s[i]>='0'&&s[i]<='9'){
			sz.push_back(s[i]-'0');
		}
	}
	sort(sz.begin(),sz.end());
	for(int i=sz.size()-1;i>=0;i--){
		cout<<sz[i];
	}
    return 0;
}
