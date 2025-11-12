#include<bits/stdc++.h>
using namespace std;
char ch;
vector<int> v;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>ch)
		if(ch>='0'&&ch<='9') v.push_back(ch^48); 
	sort(v.rbegin(),v.rend());
	for(int i:v) cout<<i;
	return 0;
}
