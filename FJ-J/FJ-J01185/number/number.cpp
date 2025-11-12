#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int num[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>s;
	int len=s.length();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		if(num[i]){
			for(int j=1;j<=num[i];j++){
				cout<<i;
			}
		}
	}
	return 0;
}
