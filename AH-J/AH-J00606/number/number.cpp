#include<bits/stdc++.h>
using namespace std;
int d[1000010];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=0,x=s.size();
	for(int i=0;i<x;i++)
		if(s[i]>='0'&&s[i]<='9')
			d[++len]=s[i]-'0';
	sort(d+1,d+1+len,cmp);
	if(d[1]==0){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=len;i++)
		cout<<d[i];
	return 0;
}
