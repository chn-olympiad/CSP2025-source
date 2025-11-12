#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;cin>>s;
	int n=s.size();
	int a[1000001];
	memset(a,-1,sizeof(a));
	for(int i=0;i<n;i++)
	if(s[i]<='9'&&s[i]>='0')
	a[i]=s[i];
	sort(a,a+n);
	for(int i=n-1;i>=0;i--){
		if(a[i]==-1) break;
	cout<<a[i]-48;
	}
	return 0;
}
