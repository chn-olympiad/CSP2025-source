#include<bits/stdc++.h>
using namespace std;
int a[1000005],cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[i]=s[i]-'0';
			cnt++;
		}
	}
	sort(a,a+len);
	for(int i=len-1;i>=len-cnt;i--)
	cout<<a[i];
	return 0;
}