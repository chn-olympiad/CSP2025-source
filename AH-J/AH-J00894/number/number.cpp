#include<bits/stdc++.h>
using namespace std;
long long t[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long len=s.size();
	for(long long i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			t[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		if(t[i]>0){
			for(int j=0;j<t[i];j++){
				cout<<i;
			}
		}
	}
	return 0;
}
