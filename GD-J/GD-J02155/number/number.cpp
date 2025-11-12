#include<bits/stdc++.h>
using namespace std;
int p[10];
string s;
int main(){
	freopen("number.out","w",stdout);
	freopen("number.in","r",stdin);
	cin>>s;
	for(int i=1;i<=s.size();i++){
		if(s[i]>='0' and s[i]<='9') p[s[i]-'0']++;
	}for(int i=9;i>=0;i--){
		for(int j=1;j<=p[i];j++){
			cout<<i;
		}
	}
}
