#include<bits/stdc++.h>
#define TIMU (string)"number"
using namespace std;
int t[91];
int main(){
	freopen((TIMU+".in").c_str(),"r",stdin);freopen((TIMU+".out").c_str(),"w",stdout);ios::sync_with_stdio(false);cin.tie(nullptr);
	string in_s = "";
	string digit = "";
	cin>>in_s;
	for(char c : in_s){
		if(isdigit(c)) digit+=c;
	}
	//cout<<"digit = "<<digit<<endl;
	for(char c : digit){
		t[(int)c^48]++;
	}
	string res = "";
	for(int i = 9;i>=0;i--){
		for(int j = 0;j<t[i];j++){
			res += (char)(48+i);
		}
	}
	cout<<res;
	return 0;
}


