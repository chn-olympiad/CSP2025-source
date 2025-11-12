#include<bits\stdc++.h>
#define ll long long
#define endl '\n'
#define str string
#define sh short
using namespace std;
str s;
vector<int> v;
bool cmp(int a,int b){
	return a>b;
}
int main(int argc,char *argv[]){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++)
	 if(isdigit(s[i]))
	  v.push_back(s[i]-'0');
	sort(v.begin(),v.end(),cmp);
//	for(auto i:v)
//	 cout<<i<<' ';
	if(v.front()==0){
		cout<<0;
		return 0;
	}
	for(auto i:v)
	 cout<<i;
	return 0;
}