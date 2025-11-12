#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	cin>>s;
	long long shu[10]={0};
	for(long long i=0;i<s.length();i++) if(s[i]>='0'&&s[i]<='9') shu[s[i]-'0']++;
	int i=9;
	while(i>=0){
		if(shu[i]){
			cout<<i;
			shu[i]--;
		}
		else i--;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}