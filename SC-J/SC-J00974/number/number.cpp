#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	string s;cin>>s;
	int ans=0;
	vector<char>A(s.size()+1);
	for(int i=0;i<s.size();i++){
		A[i+1]=s[i];
		if(A[i+1]>='0'&&A[i+1]<='9')ans++;
	}
	sort(A.begin(),A.end());
	for(int i=ans;i>=1;i--)cout<<A[i];
	return 0;
}