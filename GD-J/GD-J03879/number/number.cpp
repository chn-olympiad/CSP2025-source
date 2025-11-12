#include<bits/stdc++.h>
using namespace std;
const int M=1e6+233;
int t[20],len;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0' && s[i]<='9'){
			t[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
		while(t[i]){
			t[i]--;
			cout<<i;
		}
	return 0;
} 
