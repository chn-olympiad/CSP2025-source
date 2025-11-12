#include<bits/stdc++.h>
using namespace std;
int a[1000005],cnt=1,n=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;s[i];i++){
		if(s[i]>='0'&&s[i]<='9') a[cnt]=s[i]-48,cnt++,n++;
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--) cout<<a[i];
	return 0;
}
