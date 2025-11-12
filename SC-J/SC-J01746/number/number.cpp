#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long k=s.length(),n=1,b=0;
	for(long long i=0;i<k;i++)
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9')
			a[n]=s[i]-'0',n++;
	sort(a,a+n);
    for(long long i=n-1;i>0;i--)
		cout<<a[i];
	return 0;
}