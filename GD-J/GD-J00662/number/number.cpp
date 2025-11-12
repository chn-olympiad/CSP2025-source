#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
ll len,a[1000010],b[1000010],cnt;
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++)a[i]=s[i]-'0';
	sort(a,a+len,cmp);
	for(int i=0;i<len;i++)if(a[i]<=9&&a[i]>=0)b[++cnt]=a[i];
	if(len==cnt){
		for(int i=0;i<len;i++)cout<<a[i];
		return 0;
	}
	for(int i=1;i<=cnt;i++)cout<<b[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
