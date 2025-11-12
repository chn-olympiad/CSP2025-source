#include<bits/stdc++.h>
using namespace std;
int cnt[1000010];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(char p:s)
	if('0'<=p&&p<='9')
	cnt[++cnt[0]]=p-'0';
	sort(cnt+1,cnt+cnt[0]+1);
	for(int i=cnt[0];i>0;i--)
	cout<<cnt[i];
	return 0;
}
