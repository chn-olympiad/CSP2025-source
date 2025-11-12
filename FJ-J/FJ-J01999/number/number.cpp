#include<bits/stdc++.h>
#define ll long long
#define de double
#define MAXN 1000005
using namespace std;
string str;
int ans[MAXN];
int cnt=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(int i=0;i<(int)str.size();i++){
		if('0'<=str[i]&&str[i]<='9') 
			ans[++cnt]=str[i]-'0';
	}
	sort(ans+1,ans+cnt+1,cmp);
	for(int i=1;i<=cnt;i++) cout<<ans[i];
	return 0;
}
