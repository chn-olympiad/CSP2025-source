#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
char s[1000006];
int num[1000006];
int allnum;
bool cmp(int x,int y){
	return x>y;
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=strlen(s);
	int cnt=0;
	for(int i=0;i<n;i++) if(isdigit(s[i])) num[++cnt]=(s[i]-'0');
	sort(num+1,num+1+cnt,cmp);
	for(int i=1;i<=cnt;i++) cout<<num[i];
	return 0;
}