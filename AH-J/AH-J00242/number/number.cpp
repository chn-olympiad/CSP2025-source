#include<bits/stdc++.h>
using namespace std;
vector<int>a;
bool cmp(int x,int y){return x>y;}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	string s;cin>>s;
	for(auto i:s)
		if(isdigit(i))a.push_back(i-'0');
	sort(a.begin(),a.end(),cmp);
	if(a[0]==0)cout<<0;
	else for(auto i:a)cout<<i;
    return 0;
}
