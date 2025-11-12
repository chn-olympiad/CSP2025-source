#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6;
bool comp(const char &a,const char &b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	sort(s.begin(),s.end(),comp);
	for(auto it:s){
		if(it>='0'&&it<='9') cout<<it;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
