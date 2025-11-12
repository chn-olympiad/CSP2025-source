#include<bits/stdc++.h>
#define int long long 
using namespace std;
string s;
int ac[1000005],cnt;
bool cmp(int x,int y){
	return x>y;
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar(x%10^48);
	return;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') ac[++cnt]=s[i]-'0';
	}
	sort(ac+1,ac+cnt+1,cmp);
	for(int i=1;i<=cnt;i++) write(ac[i]);
	return 0;
}
