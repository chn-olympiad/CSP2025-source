#include<bits/stdc++.h>
using namespace std;
string s;
int ans[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;s[i]!='\0';i++)if(s[i]>='0'&&s[i]<='9')ans[(int)(s[i]-'0')]++;
	for(int i=9;i>=0;i--){
		if(ans[i]!=0){
			while(ans[i]){
				cout<<i;
				ans[i]--;
			}
		}
	}
	return 0;
}
