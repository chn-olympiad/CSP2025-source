#include<bits/stdc++.h>
using namespace std;
string s;
long long num=0,a[1000000],k=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int len=s.size();
    for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9')a[++k]=s[i]-'0';
	}
	sort(a+1,a+1+k);
	if(a[k]==0)cout<<'0';
	else for(int i=k;i>0;i--)cout<<a[i];
    return 0;
   }
