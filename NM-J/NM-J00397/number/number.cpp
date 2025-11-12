#include<bits/stdc++.h>
using namespace std;
const int N = 11;
int num[N];
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	cin>>s;
	for(int i = 0;i < s.size();i++){
		num[s[i]-'0']++;
	}
	for(int i = 9;i >= 0;i--){
		if(num[i]==0) continue;
		while(num[i]>0) cout<<i,num[i]--;
	}
	return 0;
}
