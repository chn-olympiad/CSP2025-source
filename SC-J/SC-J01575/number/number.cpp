#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],n=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if((s[i]>'0'||s[i]=='0')&&(s[i]<'9'||s[i]=='9'))
		{
			a[n]=s[i]-'0';n++;
		}
	}
	sort(a,a+n);
	for(int i=n-1;i>=0;i--){
	   printf("%d",a[i]);
	}
	return 0;
}
