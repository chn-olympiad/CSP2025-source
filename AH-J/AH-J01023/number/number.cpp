#include<bits/stdc++.h>
using namespace std;
map<char,int> t;
int main(){
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int sl=s.size();
	for(int d=0;d<sl;d++){
		t[s[d]]++;
	}
	for(char d='9';d>='0';d--){
		for(int d1=1;d1<=t[d];d1++){
			cout<<d;
		}
	}
    fclose(stdin);
    fclose(stdout);
	return 0;
}
