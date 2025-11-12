#include<bits/stdc++.h>
using namespace std;
string s;
int num[10];
int main(){
//	freopen("number4.in","r",stdin);
//	freopen("number4.out","w",stdout);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]-'0'>=0&&s[i]-'0'<=9){
			num[s[i]-'0']++;
		} 
	}
	for(int i=9;i>=0;i--){
		if(num[i]!=0){
			for(int j=1;j<=num[i];j++){
				cout<<i;
			}
		}
	}
	return 0;
} 
