#include<bits/stdc++.h>
using namespace std;
vector<int> a;
char s;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>s) {
		if(s>='0' && s<='9') a.push_back(s-'0');
	}
	sort(a.begin(),a.end(),cmp);
	for(int i=0;i<a.size();i++) cout<<a[i];
	return 0;
}