#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1000100;
string s;
int cnt,a[N];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') cnt++,a[cnt]=s[i]-'0';
	}
	sort(a+1,a+1+cnt,cmp);
	for(int i=1;i<=cnt;i++) printf("%lld",a[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}