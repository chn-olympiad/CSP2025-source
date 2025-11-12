#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
bool cmp(int x,int y){
	return x>y;
}
int main()
{
	//ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=0;
	memset(a,-1,sizeof(a));
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[i]=s[i];
		}
	}
	for(int i=0;i<s.size();i++){
		if(a[i]!=-1)	l++;
	}
	sort(a,a+s.size(),cmp);
	for(int i=0;i<l;i++){
		cout<<a[i]-'0';
	}
	return 0;
}
