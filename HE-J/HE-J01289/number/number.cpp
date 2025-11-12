#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int const N=100000;
string s;
int t[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		t[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		while(t[i]--)cout<<i;	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

