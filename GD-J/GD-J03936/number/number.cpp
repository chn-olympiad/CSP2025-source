#include<bits/stdc++.h>
using namespace std;
string s;
vector<int>e;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		char c=s[i];
		if('0'<=c&&c<='9'){
			e.push_back((int)(c-'0'));
		}
	}
	sort(e.begin(),e.end(),cmp);
	for(int i:e){
		cout<<i;
	}
	return 0;
} 
