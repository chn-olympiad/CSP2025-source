#include<bits/stdc++.h>
#define ll long long
using namespace std;

string s,t;
vector<int> v;

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("number.in" ,"r",stdin );
	freopen("number.out","w",stdout);
	
	cin>>s;
	for(char c:s){
		if(c>='0'&&c<='9') v.push_back(c-'0');
	}
	sort(v.begin(),v.end(),cmp);
	for(int x:v) cout<<x;
	
	return 0;
}

