#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	getline(cin,s);
	vector<int> vec;
	int x=s.size();
	for(int i=0;i<x;i++){
		if(s[i]<='9' && s[i]>='0'){
			vec.push_back((int)s[i]-48);
		}
	}
	int y=vec.size();
	int a[y];
	for(int i=0;i<y;i++){
		a[i]=vec[i];
	}
	sort(a,a+y);
	for(int i=y-1;i>=0;i--){
		cout << a[i];
	}
	return 0;
}
