#include<bits/stdc++.h>
using namespace std;
int n[1005];
int n2[1005];
int main(){
 	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int d2=0;
	for(int i=0;i<=s.size();i++){
		if(s[i]<='9' && s[i]>='0'){
			d2++;
			n2[(s[i]-'0')]++;
		}
	}
	for(int i=9;i>=0;i--){
		if(n2[i]>=1){
			for(int j=1;j<=n2[i];j++){
				cout<<i;
			}
		}
	}
	return 0;
}
