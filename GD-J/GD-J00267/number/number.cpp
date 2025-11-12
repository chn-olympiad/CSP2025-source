#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
char s[N];
long long bu[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int i=0;
	while(cin>>s[++i]){
		if(s[i]<='9'&&s[i]>='0'){
			bu[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=bu[i];j++){
			printf("%d",i);
		}
	}
	return 0;
} 
