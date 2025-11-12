#include<bits/stdc++.h>
#include<string>
using namespace std;
int shu[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.size(),a[l],j=0;
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			shu[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<shu[i];j++){
			cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 