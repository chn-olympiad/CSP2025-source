#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	vector<int> A;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			A.push_back(s[i]-'0');
		}
	}
	sort(A.begin(),A.end());
	for(int i=A.size()-1;i>=0;i--){
		if(A[A.size()-1]==0){
			cout<<"0";
			return 0;
		}
		cout<<A[i];
	}
	return 0;
}
