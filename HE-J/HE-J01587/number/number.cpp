#include<bits/stdc++.h>
using namespace std;
string s;
int a[1001000],j;
bool cmp(int c,int d){
	return c>d;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0' && s[i]<='9') a[++j]=s[i]-'0';
	}
	sort(a+1,a+1+j,cmp);
	for(int i=1;i<=j;i++) printf("%d",a[i]);
	return 0;
}
