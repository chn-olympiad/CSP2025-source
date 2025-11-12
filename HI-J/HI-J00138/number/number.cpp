#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e6+6;
char a[N];
bool cmp(char a,char b){
	return a>b;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int cnt=0;
	for(int i=0;i<s.size();i++){
		char c=s[i];
		if(c>='0'&&c<='9')a[++cnt]=c;
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)cout<<a[i];
	
	return 0;
}
