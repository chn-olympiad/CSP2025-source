#include<bits/stdc++.h>
using namespace std;
long long t[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	long long shu=0;
	cin>>s;
	long long cd=s.size();
	for(int i=0;i<cd;i++){
		if(s[i]>='0'&&s[i]<='9'){
			shu=int(s[i])-48;
			t[shu]++;
		}
	}
	for(int i=10;i>=0;i--){
		for(int j=1;j<=t[i];j++){
			cout<<i;
		}
	}
	return 0;
}
