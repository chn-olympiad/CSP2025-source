#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=9;i>=0;i--){
		for(int j=0;j<l;j++){
			if(s[j]-'0'==i){
				cout<<i;
				s[j]='a';
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
