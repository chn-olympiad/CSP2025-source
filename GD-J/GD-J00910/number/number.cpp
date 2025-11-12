#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
using namespace std;
string s;
const int N=1e7+10;
int a[N],cnt=0,ans=0,cnt2=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=1;i<=len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			cnt++;
			a[cnt]=int(s[i]);
		}
	}
	sort(a+1,a+cnt+1);
	for(int i=1;i<=cnt;i++){
		ans=ans+a[i]*cnt2;
		cnt2*=10;
	}
	cout<<ans;
	return 0;
}
