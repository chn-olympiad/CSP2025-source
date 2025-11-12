#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a;
	int s[11]={0};
	while(cin>>a){
		if(a>='0'&&a<='9'){
			int i=(int)a-'0';
			s[i]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=s[i];j++){
			cout<<i;
		}
	}
	return 0;
}
