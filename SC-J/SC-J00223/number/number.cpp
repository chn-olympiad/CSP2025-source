#include<bits/stdc++.h>
using namespace std;

vector<int> v;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			v.push_back(s[i]-'0');
		}
	}
	sort(v.begin(),v.end());
	int l=v.size();
	if(l>1&&v[l-1]==0){
		printf("%d",0);
		return 0;
	}
	for(int i=l-1;i>=0;i--){
		printf("%d",v[i]);
	}
	return 0;
}