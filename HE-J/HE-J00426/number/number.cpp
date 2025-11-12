#include<bits/stdc++.h>
using namespace std;
string s1;
int s[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s1;
	int l=0;
	for(int i=0;i<s1.size();i++){
		if(s1[i]>='0'&&s1[i]<='9')s[s1[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		if(s[i]==0)continue;
	  	for(int j=1;j<=s[i];j++){
			cout<<i;
		}
	}
	cout<<endl;
	return 0;
}
