#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string a;
	cin >> a;
	vector<int> x;
	for(int i=0;i<a.size();i++){
		if(isdigit(a[i])) x.push_back(a[i]-'0');
	}
	sort(x.begin(),x.end());
	for(int i=x.size()-1;i>=0;i--){
		cout << x[i];
	}
	return 0;
}
