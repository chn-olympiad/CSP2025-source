#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	vector<int>a;
	string s;
	int sum=0;
	cin>>s;
	for(int i=0;i<s.size();i++){
		int c=char(s[i]);
		//cout<<c<<" ";
		if(48<=c && c<=57){
			a.push_back(c-48);
			sum++;
		}
	}
	sort(a.begin(),a.end(),cmp);
	for(int i=0;i<sum;i++){
		cout<<a[i];
	}
}
