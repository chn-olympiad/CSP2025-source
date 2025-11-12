#include<bits/stdc++.h>
using namespace std;
string s;
bool gg;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=9;i>=0;i--){
		for(int j=0;j<s.size();j++){
			if(s[j]>='0'&& s[j]<='9'){
				if(int(s[j]-'0')==i){
					cout<<i;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}