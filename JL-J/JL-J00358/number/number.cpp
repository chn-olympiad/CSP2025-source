#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int b;
	vector<int> c;
	for(b=0;b<a.length();b++){
		if(a[b]<60){
			c.push_back(a[b]-48);
		}
	}
	sort(c.begin(),c.end());
	for(b=c.size()-1;b>=0;b--){
	    cout<<c[b];
	}
	return 0;
}
