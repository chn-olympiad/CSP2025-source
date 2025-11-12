#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;cin>>s;
	int a=s.size();
	int tong[20];
	memset(tong,0,sizeof tong);
	while(a--){
		char c=s[a];
		if(c<='z' && c>='a') continue;
		if(c<='9' && c>='0') tong[c-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=tong[i];j++) cout<<i;
	}cout<<'\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
