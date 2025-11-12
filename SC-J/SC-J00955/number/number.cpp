#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s; cin>>s;
	int x=s.size();
	vector<int> a(x);
	int cnt=0;
	for(char &c:s){
		if(isdigit(c)) a[cnt]=c-'0',cnt++;
	}
	sort(a.begin(),a.end(),greater<>());
	for(int i=0;i<cnt;i++) cout<<a[i];
	cout<<"\n";
	return 0;
}