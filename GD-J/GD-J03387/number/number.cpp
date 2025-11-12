#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int sum[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if('0'<=s[i]&&s[i]<='9') sum[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=sum[i];j>0;j--) cout<<i;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
