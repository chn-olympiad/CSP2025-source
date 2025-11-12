#include<bits/stdc++.h>
using namespace std;
string s,a;
vector<int> b;
long long sum=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.length();
	for(int i=0;i<len;i++){
		if((s[i]-'0')<10){
			a=a+s[i];
			b.push_back(s[i]-'0');
		}
	}
	sort(b.begin(),b.end(),cmp);
	for(int i=0;i<a.length();i++){
		cout<<b[i];
	}
	return 0;
} 
