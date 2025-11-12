#include<bits/stdc++.h>
using namespace std;
string s;
int ans[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len = s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			int res = s[i]-'0';
			ans[res]++;
		}
	}
	for(int i=9;i>=0;i--){
		if(ans[i]){
			for(int j=1;j<=ans[i];j++){
				printf("%d",i);
			}
		}
	}
	return 0;
}
