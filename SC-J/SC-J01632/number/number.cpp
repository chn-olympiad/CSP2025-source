#include<bits/stdc++.h>
using namespace std;
string s;
int buc[15];
int main(){

	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			buc[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(buc[i]!=0){
			cout<<i;
			buc[i]--;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
