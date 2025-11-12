#include<bits/stdc++.h>
using namespace std;
string s;
int b[78];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			b[s[i]-'0']++;
		}
	}
	int f=0;
	for(int i=9;i>=0;i--){
		if(i==0&&f==0){
			cout<<0;
			break;
		}
		for(int j=b[i];j>0;j--){
			cout<<i;
		}
	}
	return 0;
}
