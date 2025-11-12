#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>s;
	int n=s.length(),len=0;
	for(int i=0;i<n;i++)
		if(s[i]>='0'&&s[i]<='9')
			a[++len]=s[i]-'0';
	sort(a+1,a+len+1,cmp);
	for(int i=1;i<=len;i++)cout<<a[i];
	return 0;
}
