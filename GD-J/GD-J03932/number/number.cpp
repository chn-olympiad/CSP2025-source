#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
const int N=1e6+7;
int a[N],n,leng;
string s;
bool cmp(int &a,int &b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>s;
	leng=s.length();
	for(int i=0;i<leng;i++)
		if(s[i]>='0'&&s[i]<='9')
			a[++n]=int(s[i]-'0');
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
		cout<<a[i];
	return 0;
}
