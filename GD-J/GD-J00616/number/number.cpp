#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+6;
int cnt;
int num[maxn];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9')
			num[++cnt]=(int)(s[i]-'0');
	sort(num+1,num+1+cnt,cmp);
	for(int i=1;i<=cnt;i++) cout<<num[i];
	return 0;
}
