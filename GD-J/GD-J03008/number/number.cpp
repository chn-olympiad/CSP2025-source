#include<bits/stdc++.h>
#define ll long long
#define file(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
using namespace std;
const int N=1e6+30;
map<int,int> mp;
char st[N];
int main(){
	file(number);
	scanf("%s",st+1);
	int len=strlen(st+1);
	for(int i=1;i<=len;i++){
		if(st[i]>='0' && st[i]<='9'){
			mp[st[i]-'0']++;
		}
	}
	bool flag=0;
	for(int i=9;i>0;i--){
		if(mp[i])flag=1;
	}
	if(!flag){
		cout<<0<<endl;
		return 0;
	}
	for(int i=9;i>=0;i--){
		while(mp[i]--) cout<<i;
	}
	return 0;
}

