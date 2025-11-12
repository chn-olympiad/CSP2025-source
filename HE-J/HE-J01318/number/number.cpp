#include<bits/stdc++.h>
using namespace std;
string s;
int len,a[1000010],len2;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0' && s[i]<='9'){
			a[++len2]=s[i]-'0';
		}
	}
	sort(a+1,a+len2+1);
	for(int i=len2;i>=1;i--){
		printf("%d",a[i]);
	}
	return 0;
}
