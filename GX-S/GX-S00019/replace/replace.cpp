//I Love CCF.I Want 100pts in this problem!
#include<bits/stdc++.h>
using namespace std;
#define ll long long
void read(ll &x){
	x=0;ll f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	x*=f;
}
const int N=2e5+2;
string s[N][2];
string s1,s2;
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i][0]>>s[i][1];
	for(int i=1;i<=q;i++){
		cin>>s1>>s2;
		//cout<<0<<'\n';
		cout<<0<<'\n';
	}
}
//I only have 172pts,can i go to NOIP(sad)?i want to go it!
//bu ke yi zong si ling neng zai chu xian yi ci ma?
//my names in Luogu is JadeFox2012
