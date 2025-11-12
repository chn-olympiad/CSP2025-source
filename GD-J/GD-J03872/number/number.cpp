#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
string s;
int shu[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			shu[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		if(shu[i]==0){
			continue;
		}
		while(shu[i]){
			cout<<i;
			shu[i]--;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
