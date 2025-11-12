#include <bits/stdc++.h>
using namespace std;
string s;
int t[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0' && s[i]<='9'){
			int x=s[i]-'0';
			t[x]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=t[i];j++){
			cout<<i;
		}
	}
	fclose(stdout);
	fclose(stdout);
	return 0;
}

