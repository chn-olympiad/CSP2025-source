#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace{
	void Main(){
		cin.tie(0)->sync_with_stdio(0);
		freopen("number.in","r",stdin);
		freopen("number.out","w",stdout);
		string s;
		cin>>s;
		string t="";
		for(auto &i:s) if(isdigit(i)) t+=i;
		sort(t.begin(),t.end(),greater<char>());
		cout<<t;
	} 	
} 
main(){Main();}

