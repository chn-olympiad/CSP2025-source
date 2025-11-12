#include <bits/stdc++.h>
using namespace std;
string s;
int a[15],b;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	b=s.size();
	for(int i=0;i<b;i++){
		if(s[i]-'0'>=0&&s[i]-'0'<=9){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=a[i];j>0;j--){
			cout<<i;
		}
	}
	return 0;
}
