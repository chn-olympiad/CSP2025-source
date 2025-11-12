#include<bits/stdc++.h>
using namespace std;
int n, q;
vector<int> temp1, temp2;
map<pair<vector<int>, vector<int> >, int> mp;
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin>>n>>q;
	string s1, s2;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		temp1.clear();
		temp2.clear();
		for(int j=0;j<s1.size();j++){
//			if(s1[i] == s2[i]) continue;
			temp1.push_back(s1[j]-'a');
			temp2.push_back(s2[j]-'a');
		}
		mp[{temp1, temp2}]++;
//		for(int k=0;k<temp1.size();k++) cout<<char(temp1[k]+'a');
//		cout<<" ";
//		for(int k=0;k<temp2.size();k++) cout<<char(temp2[k]+'a');
//		cout<<" "<<mp[{temp1, temp2}]<<endl;
	}
	string t1, t2;
	while(q--){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<endl;
			continue;
		}
		int cnt = 0;
		int l=0;
		while(t1[l] == t2[l]) l++;
		int r = l+1;
		while(r<t1.size() && t1[r] != t2[r]) r++;
		r--;
//		cout<<l<<" "<<r<<endl;
		for(int i=0;i<=l;i++){
			temp1.clear();
//			cout<<temp1.size()<<endl<<endl;
			temp2.clear();
			for(int j=i;j<r;j++){
				temp1.push_back(t1[j]-'a');
				temp2.push_back(t2[j]-'a');
			}
			for(int j=r;j<t1.size();j++){
				temp1.push_back(t1[j]-'a');
				temp2.push_back(t2[j]-'a');
				cnt += mp[{temp1, temp2}];
//				for(int k=0;k<temp1.size();k++) cout<<char(temp1[k]+'a');
//				cout<<" ";
//				for(int k=0;k<temp2.size();k++) cout<<char(temp2[k]+'a');
//				cout<<" "<<cnt<<endl;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
} 
