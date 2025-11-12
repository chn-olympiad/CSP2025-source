#include<bits/stdc++.h>
using namespace std;
string str;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	vector<int> a;
	for(int i=0;i<str.size();i++){
		if(str[i]>='0' && str[i]<='9'){
			a.push_back(str[i]-'0');
		}
	}
	sort(a.begin(),a.end(),cmp);
	for(int i=0;i<a.size();i++){
		cout<<a[i];
	}
	return 0;
}
