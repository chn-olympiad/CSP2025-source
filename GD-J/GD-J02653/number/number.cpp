#include<bits/stdc++.h>
using namespace std;
bool f(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	vector<int> v;
	for(int i=0;i<a.size();i++)if('0'<=a[i]&&a[i]<='9')v.push_back(a[i]-'0');
	int b=v.size();
	sort(v.begin(),v.end(),f);
	for(int i=0;i<v.size();i++){
		cout<<v[i];
	} 
	return 0;
} 
