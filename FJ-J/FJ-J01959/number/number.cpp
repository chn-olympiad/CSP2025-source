#include<bits/stdc++.h>
using namespace std;
#define int long long
char a[1000002];
bool cmp(char a,char b){
	return a>b;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size(),cnt=0;
	for(int i=0;i<n;i++)if(s[i]<='9'&&s[i]>='0')a[cnt++]=s[i];
	sort(a,a+cnt,cmp);
	for(int i=0;i<cnt;i++)cout<<a[i];
	return 0;
} 
