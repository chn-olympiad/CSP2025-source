#include<bits/stdc++.h>
using namespace std;

string s;
long long ton[110];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			ton[s[i]-'0']+=1;
		}
	}
	for(long long i=9;i>=0;i--){
		while(ton[i]!=0){
			ton[i]--;
			cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
