#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,num[N],idx;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s,s=" "+s;
	n=s.size()-1;
	for(int i=1;i<=n;i++)
		if(s[i]>='0'&&s[i]<='9')num[++idx]=s[i]-'0';
	sort(num+1,num+1+idx);
	if(num[idx]==0)idx=1;
	for(int i=idx;i>=1;i--)
		printf("%d",num[i]);
	return 0;
}
