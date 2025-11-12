#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm> 
#include<cstdio>
using namespace std;

bool cop(int a,int b){
	return a>b;
}
string str;
vector<int> a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(int i=0;i<str.size();i++)if(str[i]>='0'&&str[i]<='9')a.push_back(str[i]-'0');
	sort(a.begin(),a.end(),cop);
	for(int i=0;i<a.size();i++)cout<<a[i];
	
	
	return 0;
}
