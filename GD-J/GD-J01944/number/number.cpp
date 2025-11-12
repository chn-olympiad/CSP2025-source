#include <bits/stdc++.h>
using namespace std;

string s;
long long a,b,c,ls[1005];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			a = s[i]-48;
			ls[a]++;
		}
	}
	for(int i=9;i>=0;i--){
		if(ls[i]>0){
			for(int j=1;j<=ls[i];j++){
				cout<<i;
			}
		}
	}
	
	return 0;
}
