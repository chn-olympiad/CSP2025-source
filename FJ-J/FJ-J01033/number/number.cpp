#include<bits/stdc++.h> 
using namespace std;
string s;
int n=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	vector<string>a(s.size()+1);
	for(int i=0;i<s.size();i++){
		if(s[i]<'a'){
			a[n]=s[i];
			n++;
		}
	}
	sort(a.begin(),a.end(),greater<string>());
	for(int i=0;i<n;i++){
		cout<<a[i];
	}
	return 0;
}
