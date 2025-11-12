#include<bits/stdc++.h>
#define N 1000005
using namespace std;

string ss,ans="";

int st[N],tot=0,sz;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>ss;
	sz=ss.size();
	for(int i=0;i<sz;i++){
		if('0'<=ss[i]&&ss[i]<='9'){
			st[++tot]=int(ss[i]-'0');
		}
	}
	sort(st+1,st+tot+1);
	for(int i=tot;i>=1;i--)ans=ans+char(st[i]+'0');
	cout<<ans;
	return 0;
}
