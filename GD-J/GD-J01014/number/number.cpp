#include<bits/stdc++.h>
using namespace std;
string s;
int ans[2000000],cnt;
bool cmp(int a,int b){return a>b;}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;int len=s.length();
	for(int i=0;i<len;i++){
		if(isdigit(s[i])){
			ans[++cnt]=s[i]-'0';
		}
	}
	sort(ans+1,ans+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)cout<<ans[i];
} //[100,100]
