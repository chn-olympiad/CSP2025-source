#include<bits/stdc++.h>
using namespace std;
string s;
int num[1000005],cnt;
signed main(){
	freopen("number.in","r",stdin),freopen("number.out","w",stdout);
	cin>>s;
	for(char i:s)
		if(i>='0'&&i<='9')
			num[++cnt]=i-'0';
	sort(num+1,num+cnt+1);
	for(int i=cnt;i>=1;i--) printf("%d",num[i]);
	return puts(""),0;
}
