#include<bits/stdc++.h>
using namespace std;
string s;
int a[10],n,i;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	memset(a,0,sizeof(a));
	cin>>s;
	n=s.size();
	for(i=0;i<n;i++)if(s[i]>='0'&&s[i]<='9')a[s[i]-'0']++;
	for(i=9;i>=0;i--)while(a[i]--)cout<<i;
	return 0;
}
