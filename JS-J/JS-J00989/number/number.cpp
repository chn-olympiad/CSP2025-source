#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
string s;
int a[maxn]={-1};
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int cnt=0;
	for(int i=0;i<s.size();i++)
		if(isdigit(s[i])) a[++cnt]=s[i]-'0';
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		if(a[i]==-1) break;
		cout<<a[i];
	}
	return 0;
}
