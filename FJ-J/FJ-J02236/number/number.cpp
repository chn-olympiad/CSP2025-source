#include<bits/stdc++.h>
using namespace std;
int n,mx=0,a[1000005],cnt=0;
char s[1000005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=strlen(s);
	for(int i=0;i<len;i++){
		if(s[i]<='9'&&s[i]>='0'){
			cnt++;
			a[cnt]=s[i]-'0';
		} 
	}
	sort(a+1,a+cnt+1,cmp);
	cout<<a[1];
	for(int i=2;i<=cnt;i++){
		cout<<a[i];
	}
	return 0;
}
