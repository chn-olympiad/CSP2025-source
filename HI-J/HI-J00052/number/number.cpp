#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	vector<int>b;
	getline(cin,a);
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			b.push_back(a[i]-'0');
		}
	}
	sort(b.begin(),b.end(),cmp);
	if(b[0]==0)
		{
			cout<<0;
			return 0;
		}
	for(int i=0;i<b.size();i++){
		
		cout<<b[i];
	}
	return 0;
} 
