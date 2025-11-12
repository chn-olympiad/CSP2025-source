#include<bits/stdc++.h>
using namespace std;
string s;
map<int,int> mp;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int t=s.size();
    for(int i=0;i<t;i++){
	    mp[s[i]-'0']++;
	}
    for(int i=9;i>=0;i--)
	    while(mp[i]>0) {
			mp[i]--;
			cout<<i;
	   }
}
