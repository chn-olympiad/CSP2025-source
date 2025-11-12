#include <bits/stdc++.h>
using namespace std;
int opnum[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string str;
	cin>>str;
	int a=0;
	for(int i=0;i<str.size();i++){
		if(str[i]-'0'>=0&&str[i]-'0'<=9){
			opnum[++a]=str[i]-'0';
		}
	}
	sort(opnum,opnum+a+1);
	for(int i=a;i>=1;i--){
		cout<<opnum[i];
	}
	
	return 0;
}
