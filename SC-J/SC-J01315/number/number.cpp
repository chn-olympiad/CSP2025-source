#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int N=1e5+5;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string str;
	cin>>str;
	vector<int> V;
	for(int i=0;i<str.size();i++){
		if(str[i]>='0'&&str[i]<='9') V.push_back(int(str[i]-'0'));
	}
	sort(V.begin(),V.end(),cmp);
	for(int i=0;i<V.size();i++){
		cout<<V[i];
	}
	return 0;
} 