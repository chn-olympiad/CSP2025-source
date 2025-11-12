#include<bits/stdc++.h>
using namespace std;
vector<int> vec;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	getline(cin,n);
	for(int i=0;i<n.size();i++){
		if(isdigit(n[i])){
			vec.push_back(n[i]-'0');
		}
	}
	sort(vec.begin(),vec.end());
	for(int i=vec.size()-1;i>=0;i--){
		cout<<vec[i];
	}
	return 0;
 } 
