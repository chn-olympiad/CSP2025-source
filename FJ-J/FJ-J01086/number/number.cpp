#include<bits/stdc++.h>
using namespace std;
string s;
int n[15],t;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int t=s.size();
	for(int i=0;i<t;i++){
		if(s[i]<='9'&&s[i]>='0'){
			n[s[i]-48]++;
		}
	}for(int i=9;i>=0;i--){
		while(n[i]){
			if(n[i]<=0)break;
			else cout<<i;
			n[i]--;
		}
	}
	return 0;
}
