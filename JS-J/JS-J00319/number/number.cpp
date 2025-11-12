#include<bits/stdc++.h>
using namespace std;

unordered_map<int,int> m;
string s;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	while(s!=""){
		if((s[0]>='0')&&(s[0]<='9'))
			m[s[0]-48]++;
		s=s.substr(1);
	}
			
		
	for(int i=9;i>=0;i--){
		while(m[i]!=0){
			printf("%d",i);
			m[i]--;
		}
	}
	
	return 0;
}
