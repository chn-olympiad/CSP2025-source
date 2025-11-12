#include<bits/stdc++.h>
using namespace std;

int len,cnt;
int a[1000001];
string s;

bool compare(int a,int b){
	return a>b;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++) if(s[i]>='0'&&s[i]<='9') a[++cnt]=s[i]-'0';
	sort(a+1,a+cnt+1,compare);
	for(int i=1;i<=cnt;i++) cout<<a[i];
	return 0;
}
