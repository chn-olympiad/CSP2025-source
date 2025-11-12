#include<bits/stdc++.h>
using namespace std;
string s;
int ls;
long long n[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	ls=s.size();
	for(int i=0;i<ls;i++){
		if(s[i]>='0'&&s[i]<='9'){
			n[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=n[i];j++){
			cout<<i;
		}
	}
	return 0;
}
