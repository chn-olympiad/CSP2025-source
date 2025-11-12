#include<bits/stdc++.h>
using namespace std;
char x;
vector<int> a;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>x){
		if(x>='0'&&x<='9'){
			a.push_back(int(x)-48);
		}
	}
	sort(a.begin(),a.end(),cmp);
	for(auto i:a)cout<<i;
	return 0;
} 
