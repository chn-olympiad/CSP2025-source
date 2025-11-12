#include <bits/stdc++.h>
using namespace std;
string s;
long long b[101];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int k=s.length();
	for(int i=0;i<k;i++){
		if(s[i]>='0'&&s[i]<='9'){
			b[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(b[i]!=0){
			cout<<i;
			b[i]--;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
