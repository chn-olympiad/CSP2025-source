#include<bits/stdc++.h>
using namespace std;
string s;
int a[2000005],n,cnt=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.length();
	s=' '+s;
	for(int i=1;i<=n;i++){
		if(s[i]>='0'&&s[i]<='9') a[++cnt]=s[i]-'0';
	}
	sort(a+1,a+cnt+1);
	for(int i=cnt;i>=1;i--) printf("%d",a[i]);
	return 0;
}
