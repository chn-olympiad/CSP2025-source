#include<bits/stdc++.h>
using namespace std;
int t[19];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(auto I:s){
		if(I>='0'&&I<='9'){
			t[I-'0']++;
		}
	}
	for(int i = 9;i>=0;--i){
		for(int j = 1;j<=t[i];++j){
			cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
}
