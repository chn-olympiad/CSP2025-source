#include<bits/stdc++.h>
#define elif else if
//#define int long long
using namespace std;
int ans[114514*10],cnt;
char ch[114514*10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>ch;
	int lenc=strlen(ch);
	for(int i=0;i<lenc;i++) if(ch[i]>='0'&&ch[i]<='9') ans[cnt++]=ch[i]-'0';
	sort(ans,ans+cnt);
	if(ans[cnt-1]==0) cout<<0;
	else for(int i=cnt-1;i>=0;i--) cout<<ans[i];
	return 0;
}//#Shang4Shan3Ruo6Shui4
