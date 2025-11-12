#include<bits/stdc++.h>
using namespace std;
string s,s2;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>=48&&s[i]<=57){
			s2+=s[i];
		}
	}
	for(int i=0;i<s2.size();i++){
		for(int j=0;j<i;j++){
			if(s2[i]>s2[j]){
				swap(s2[i],s2[j]);
			}
		}
	}
	cout<<s2;
	return 0;
	}
