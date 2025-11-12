#include<bits/stdc++.h>
using namespace std;
string s;
int t[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;s[i]!='\0';i++){
		if(s[i]>='0'&&s[i]<='9'){
			int x=s[i]-48;
			t[x]++;
		}
	}
	for(int i=9;i>=0;i--){
		if(t[i]!=0){
			while(t[i]>0){
				cout<<i;
				t[i]--;
			}
		}
	}
	return 0;
}
