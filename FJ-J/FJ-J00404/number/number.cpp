#include<bits/stdc++.h>
using namespace std;
long long cou[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		char c=s[i];
		if(c>='0'&&c<='9')cou[c-'0']++;
	}
	for(int i=9;i>=0;i--){
		if(cou[i]){
			for(long long j=1;j<=cou[i];j++){
				cout<<(char)(i+'0');
			}	
		}
	}
	return 0;
}
