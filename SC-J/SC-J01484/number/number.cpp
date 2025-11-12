#include<bits/stdc++.h>
using namespace std;
string s;
vector<char>a;
int n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l;
	l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a.push_back(s[i]);
			n++;
		}
	}
	sort(a.begin(),a.end());
	for(int i=n-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
