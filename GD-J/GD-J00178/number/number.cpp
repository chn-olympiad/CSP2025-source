#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
char ch;
string s;
long long ans,a[1000005];
int cnt=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);	
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++)
		if(s[i]>='0' and s[i]<='9'){
			a[cnt++]=s[i]-'0';
		}
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++) cout<<a[i];
	return 0;
} 
