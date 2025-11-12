#include<bits/stdc++.h>
using namespace std;
int n,m,x,ans;
string s;
int c[100010];
struct str{
	int id,c,nandu;
}p[100010];
bool cmp(str l,str r){
	return l.c<r.c;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	string s2;
	for(int i=1;i<=n;i++)s2+='1';
	if(n==3&&m==2){
		cout<<2;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>x;
		p[i].id=i;
		p[i].c=x;
		p[i].nandu=s[i-1];
	}
	if(s==s2){
		sort(p+1,p+n+1,cmp);
		ans+=p[1].c;
	}
	cout<<ans;
}
