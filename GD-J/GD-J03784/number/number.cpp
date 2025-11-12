#include<bits/stdc++.h>
using namespace std;
string a;
vector<int> b;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if('0'<=a[i]&&a[i]<='9') b.push_back(a[i]-'0');
	}
	sort(b.begin(),b.end(),cmp);
	for(int i=0;i<b.size();i++) cout<<b[i];
	return 0;
}

