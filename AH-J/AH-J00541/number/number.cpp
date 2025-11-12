#include<bits/stdc++.h>
using namespace std;
int a[1000010],cnt;
bool cmp(int n,int m){
		return n>m;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)	if(s[i]>='0'&&s[i]<='9') a[++cnt]=s[i]-'0';
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++) printf("%d",a[i]);
	cout<<endl;
	return 0;
}	
