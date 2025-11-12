#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int INF=1e6+10;

int a[INF],cnt;
string s;

bool cmp(const int a1,const int a2){
	return a1>a2;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>s;
	int len=s.length();
	for (int i=0;i<len;i++){
		if (s[i]>='0'&&s[i]<='9')a[++cnt]=s[i]-'0';
	}
	sort(a+1,a+1+cnt,cmp);
	for (int i=1;i<=cnt;i++)cout<<a[i];	
	return 0;
}
