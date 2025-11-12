#include<bits/stdc++.h>//iloveu ljn&Six_flower,pls giveme mwreluck for RP++!!! 
#define int long long//if i get both J&S 1st,i'll showlove foru
using namespace std;//actructly i hope so,willu agree me?i'm not sure
int a[1000010],id;//in yourlife,i'm just a simpel friend
string s;
bool cmd(int x,int y){
	return x>y;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[++id]=(s[i]-'0');
		}
	}
	sort(a+1,a+1+id,cmd);
	for(int i=1;i<=id;i++){
		cout<<a[i];
	}
	return 0;
}
