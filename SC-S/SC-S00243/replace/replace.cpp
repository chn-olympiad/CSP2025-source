#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
int n,m;
map<string,string> s;
string cha[MAXN];
int sicha;
char repla[MAXN<<3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int iop=1;iop<=n;iop++){
		string a,b;
		cin>>a>>b;
		s[a]=b;
		cha[++sicha]=a;
	}
	for(int i=1;i<=m;i++){
		int ans=0;
		string x,y;	
		cin>>x>>y;
		for(int i=1;i<=sicha;i++){
			string xx=x;
			if(x.find(cha[i])<=x.size()){
				for(unsigned int j=x.find(cha[i]);j<x.find(cha[i])+cha[i].size();j++){
					xx[j]=s[cha[i]][j-x.find(cha[i])];
				}
//				cout<<xx<<' '<<y<<'\n';
				if(xx==y){
//					cout<<i<<'\n';
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}