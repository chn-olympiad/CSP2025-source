#include<bits/stdc++.h>
using namespace std;
string s;
int ha[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(ha,0,sizeof(ha));
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			ha[s[i]-'0']++;
			
		}
	}
	for(int i=9;i>=0;i--){
		if(ha[i]!=0){
			for(int j=1;j<=ha[i];j++) cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}