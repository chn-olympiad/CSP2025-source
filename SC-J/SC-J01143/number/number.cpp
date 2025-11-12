#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	string s;
	cin>>s;
	vector<int> A;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0' || s[i]=='1' || s[i]=='2' || s[i]=='3' || s[i]=='4' || s[i]=='5' || s[i]=='6' || s[i]=='7' || s[i]=='8' || s[i]=='9'){
			int n=s[i];
			n=n-48;
			A.push_back(n);
		}
	}
	sort(A.begin(),A.end());
	reverse(A.begin(),A.end());
	for(int i=0;i<A.size();i++) cout<<A[i];
	return 0;
}