#include<bits/stdc++.h>
using namespace std;
//#define int long long;
vector<int> a;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a.push_back(s[i]-'0');
		}
	}
	sort(a.begin(),a.end(),cmp);
	int q=0;
	for(int i=0;i<a.size();i++){
		if(q==0){
			if(a[i]==0) continue;
			else{
				cout<<a[i];
				q=1;
			}
		}
		else{
			cout<<a[i];
		}
	}
	if(q==0){
		cout<<0;
	}
	return 0;
}
//written by smartjohn