#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int ans[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=strlen(s),x=0;
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			ans[++x]=int(s[i]-'0');
		}
	}
	sort(ans+1,ans+1+x);
	for(int i=x;i>=1;i--){
		cout<<ans[i];
	}
	return 0;
} 
