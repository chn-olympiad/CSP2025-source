#include<bits/stdc++.h>
#define qwq return
#define zzz long long
using namespace std;
zzz ans[1000001],l=0;
string s;
bool sor(zzz x,zzz y){
	qwq x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(zzz i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			ans[l++]=(int)(s[i]-'0');
		}
	}
	sort(ans,ans+l,sor);
	for(zzz i=0;i<l;i++)cout<<ans[i];
	qwq 0;
}