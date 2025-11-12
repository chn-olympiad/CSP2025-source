#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	int i,t=0,a[100001];
	cin>>s;
	for(i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9')
			{
				t++;
				a[t]=s[i]-'0';
			}
	sort(a+1,a+t+1,cmp);
	for(i=1;i<=t;i++)
		printf("%d",a[i]);
	return 0;
}