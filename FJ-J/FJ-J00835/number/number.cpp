#include<bits/stdc++.h>
using namespace std;
int n[10];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' and s[i]<='9'){
			n[int(s[i])-48]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<n[i];j++){
			cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
