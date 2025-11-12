#include<bits/stdc++.h>
using namespace std;
int ct[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<(int)s.size();i++){
		if(s[i]>='0' && s[i]<='9') ct[s[i]-'0']++;
	}
	bool fl=false;
	for(int i=9;i>=0;i--){
		if(i!=0) for(int j=1;j<=ct[i];j++) fl=true,printf("%d",i);
		else{
			if(fl) for(int j=1;j<=ct[i];j++) printf("%d",i);
			else printf("0");
		}
	}
	return 0;
}