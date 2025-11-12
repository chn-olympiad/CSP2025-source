#include<bits/stdc++.h>
using namespace std;
string s;
long long t[10];
long long cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	long long l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			t[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		 for(int j=1;j<=t[i];j++){
			cout<<i;
		 }
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
