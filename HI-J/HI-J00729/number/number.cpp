#include<bits/stdc++.h>
using namespace std;
int sz[1000005];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int szxb=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			sz[szxb]=s[i]-'0';
			szxb++;
		}
	}
	sort(sz,sz+szxb);
	for(int i=szxb-1;i>=0;i--){
		cout<<sz[i]; 
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
