#include<bits/stdc++.h>
using namespace std;

string s;
const int maxn=1e6+5;
int num[maxn];
int cnt;

bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	getline(cin,s);
	int len=s.length();
	for(int i=0;i<len;i++)
		if(s[i]>='0'&&s[i]<='9')
			num[++cnt]=s[i]-'0';
	sort(num+1,num+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
		cout<<num[i];
	return 0;
}
