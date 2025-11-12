#include<bits/stdc++.h>
using namespace std;
int a[1000000]={0};
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	long long ans=0;
	int c=0;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			a[c]=s[i]-'0';
			c++;
		}
	}
	sort(a,a+c);
	for(int i=c-1;i>=0;i--){
		ans=ans*10+a[i];
	}
	cout<<ans;
	return 0;
}
