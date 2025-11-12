#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int a[105],cnt;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			cnt++;
			a[cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
		cout<<a[i];
	return 0;
}
