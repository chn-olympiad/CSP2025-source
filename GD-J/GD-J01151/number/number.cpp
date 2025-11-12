#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1000005;
string str;
int len,s[N],cur=0;
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>str;
    len=str.size();
    for(int i=0;i<len;i++)
    	if('0'<=str[i]&&str[i]<='9') s[++cur]=str[i]-'0';
    sort(s+1,s+1+cur,greater<int>());
    if(s[1]==0){
    	printf("0");
    	return 0;
	}
    for(int i=1;i<=cur;i++)
    	printf("%lld",s[i]);
	return 0;
}

