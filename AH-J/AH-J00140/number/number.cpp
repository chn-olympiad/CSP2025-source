#include<bits/stdc++.h>
using namespace std;
string s;
int b[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			b[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		if(b[i]==0)continue;
		while(b[i]--)printf("%d",i);
	}
	puts("");
	return 0;
}
