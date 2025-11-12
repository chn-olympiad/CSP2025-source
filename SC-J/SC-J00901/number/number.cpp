#include<bits/stdc++.h>
using namespace std;
const int N=1e6+3;
#define ll long long
int n,m,ans[N],pos;
string s;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++)if(s[i]>='0'&&s[i]<='9')ans[++pos]=s[i]-'0';
	sort(ans+1,ans+1+pos,cmp);
	for(int i=1;i<=pos;i++)cout<<ans[i];
	return 0;
}