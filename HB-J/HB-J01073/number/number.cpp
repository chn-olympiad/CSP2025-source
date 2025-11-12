#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int lens=0,a[11]={};
	cin>>s;
	lens=s.size();
	for(int i=0;i<lens;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	bool check=false;
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			cout<<i;
			check=true;
		}
	}
	if(check==false){
		cout<<"0";
	}
	return 0;
}
