#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.size();
	int t[10];
	int c=0;
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			t[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		if(t[i]!=0){
			for(int j=1;j<=t[i];j++){
				c=c*10+i;
			}
		}
	}
	cout<<c;
	return 0;
}
