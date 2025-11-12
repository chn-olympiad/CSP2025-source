#include<bits/stdc++.h>
using namespace std;
int mp[12];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	getline(cin,s);
	int l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			mp[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=mp[i];j++)printf("%d",i);
	}
	printf("\n");
	return 0;
}
