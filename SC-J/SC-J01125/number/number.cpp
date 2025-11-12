#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;	//最大开6e7 
int a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size();
	int cnt=0;	//统计数字个数 
	for(int i=0;i<len;i++)
		if(s[i]>='0'&&s[i]<='9')
			a[++cnt]=s[i]-'0';
	sort(a+1,a+cnt+1,greater<int>());
	for(int i=1;i<=cnt;i++)
		cout<<a[i];
} 