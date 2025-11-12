#include <bits/stdc++.h>
using namespace std;

bool o(char x, char y){
	return x>y;
}
char s[10005];
char ans[10005];





int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int i=0;
	int cnt=0;
	while(s[i]!=0){
		if(s[i]<='9'&&s[i]>='0'){
			ans[cnt]=s[i];
			cnt++;
		}
		i++;
	}
	sort(ans,ans+cnt,o);
	for(int i=0;i<cnt;i++){
		cout<<ans[i];
	}
}



