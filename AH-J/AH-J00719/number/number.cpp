#include<bits/stdc++.h>
using namespace std;
string s;
map<int,int> mp;
int c;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            mp[s[i]-'0']++;
        }
	}
	for(int i=9;i>=0;i--){

        int l=mp[i];
        for(int j=0;j<l;j++){
            cout<<i;
        }
	}
	cout<<endl;
	return 0;
}
