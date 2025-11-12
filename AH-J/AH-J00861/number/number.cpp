#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	vector<char> a;
	int q=s.length();
	for(int i=0;i<q;i++){
		if(s[i]-60<0) {
			int c=s[i];
			a.push_back(c);
		}
	}
	sort(a.begin(),a.end(),cmp);
	q=s.size();
	for(int i=0;i<q;i++){
		cout<<a[i];
	}
	return 0;
}
