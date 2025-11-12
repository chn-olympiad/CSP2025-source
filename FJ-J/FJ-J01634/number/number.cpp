#include<bits/stdc++.h>
using namespace std;
string s;
int num[11]={0,0,0,0,0,0,0,0,0,0,0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.length();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(num[i]){
			cout<<i;
			num[i]--;
		}	
	}
}
