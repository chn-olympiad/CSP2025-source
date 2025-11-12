#include<bits/stdc++.h>
using namespace std;
int sum,a[1000010];
string s;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++)
		if(s[i]>='0'&&s[i]<='9')a[sum++]=s[i]-'0';
	sort(a,a+sum,cmp);
	for(int i=0;i<sum;i++)cout<<a[i];
	return 0;
}
