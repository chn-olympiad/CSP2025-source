#include<bits/stdc++.h>
using namespace std;
const int N=2e6;
int a[N],n,t;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++)
		if(s[i]<='9'&&s[i]>='0')a[++t]=s[i]-'0';
	sort(a+1,a+t+1);
	for(int i=t;i>=1;i--)cout<<a[i];
	return 0;
}
