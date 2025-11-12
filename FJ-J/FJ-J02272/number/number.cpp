#include<bits/stdc++.h>
using namespace std;
string s;
int n,a[100005],ans=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<=n-1;i++){
		if(s[i]>='a'&&s[i]<='z')
			continue;
		else if(s[i]-'0'==0)
			ans++;
		else
			a[i]=s[i]-'0';
	}
	sort(a,a+n);
	for(int i=n-1;i>=0;i--)
	{
		if(a[i]>0&&a[i]<=9)
			cout<<a[i];
	}
	for(int i=1;i<=ans;i++)
		cout<<0;
	return 0;
}
