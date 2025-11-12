#include<bits/stdc++.h>
using namespace std;
using ll=long long;
char s[1000005],ans[1000005];
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<strlen(s);i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}for(int i=9,j=0;i>=0;i--){
		for(;a[i];a[i]--){
			ans[j]=i+'0';
			j++;
		}
	}for(int i=0;i<strlen(ans);i++) cout<<ans[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
