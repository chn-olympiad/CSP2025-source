#include<bits/stdc++.h>
using namespace std;
vector<int> numb;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long sz = s.size();
	for(long long i=0;i<sz;i++){
		if('0'<=s[i]&&s[i]<='9'){
			numb.push_back(int(s[i]-'0'));
		}
	}
	sort(numb.begin(),numb.end());
	long long vz = numb.size();
	for(int i=vz-1;i>=0;i--){
		cout<<numb[i];
	}
	return 0;
}
