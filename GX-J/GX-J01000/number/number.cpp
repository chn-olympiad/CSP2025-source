#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b) {return a>b;}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	vector<int> num;
	string s;
	cin>>s;
	for(auto z:s)if(z>='0'&&z<='9')num.push_back(z-'0');
	sort(num.begin(),num.end(),cmp);
	for(auto ans:num)cout<<ans;
	return 0;
}
//printf scanf
