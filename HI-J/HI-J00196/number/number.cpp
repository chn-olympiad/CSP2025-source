#include<bits/stdc++.h>
using namespace std;
int a[1000005],b[1000005];
bool cmp(string n1,string n2){
	return n1>n2;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	if(s.size()==1 || s.size()==2){
		cout<<s;
		return 0;
	}
	cout<<s;
	return 0;
}
