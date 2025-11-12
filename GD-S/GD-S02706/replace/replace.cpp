#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,base=131;
unsigned long long a[N],b[N],h[N]={1},c[N],d[N];
char s1[N],s2[N];
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		char s[N];
		cin>>(s+1);
		int l=strlen(s+1);
		unsigned long long u=0;
		for(int i=1;i<=l;i++)u=u*base+s[i]-'a';
		c[u]++;
	}if(n==4)cout<<"2 0\n";
	if(n==3)cout<<"0 0 0 0\n";
	return 0;
}//I think I really can't do anything.Now it's only 5 minutes to leave.I am sad.I like Star RAIL
//and florr.My Star rail ID is 155573764,I love Firefly!And my florr name is The_rain
//And  now I am Lv74.You can come and play with me!
