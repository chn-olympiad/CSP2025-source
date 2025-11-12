#include<bits/stdc++.h>
#define int long long
using namespace std;
char s[1000006];
vector<int>vec;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	for(int i=1;s[i];i++)if(s[i]>='0' and s[i]<='9')vec.push_back(-s[i]+'0');
	sort(vec.begin(),vec.end());
	if(vec[0]==0)return puts("0"),0;
	for(int i : vec)printf("%lld",-i);
	return puts(""),0;
}
