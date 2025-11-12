#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	vector<int> x;
    for(auto a:s){
    	int u=int(a)-int('0');
    	if(u<=9){
    		x.push_back(u);
		}
	}
	sort(x.begin(),x.end());
	reverse(x.begin(),x.end());
	for(auto a:x){
		cout<<a;
	}
	return 0;
}
