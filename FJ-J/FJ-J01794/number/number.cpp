#include<bits/stdc++.h>
using namespace std;
string s,n;int m=0;
int main()
{
	freopen("number.in","r",stdin);freopen("number.out","w",stdout);
	cin>>s;
	for(int i=1;i<=s.size();i++){
		if(s[i-1]-'0'>=0&&s[i-1]-'0'<=9){
			n[++m]=s[i-1];
			for(int j=m;j>=1;j--){
				if(n[j]>=n[j-1])swap(n[j],n[j-1]);
			}
		}
	}
	for(int i=0;i<=m;i++)cout<<n[i];
	return 0;
}