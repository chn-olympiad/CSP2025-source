#include<algorithm>
#include<iostream>
#include<string.h>
using namespace std;
const int N=6e5+10;
int n,q,s[N];
string a[N],b[N],c[N],d;
void cmp(int x){
	int p=0;
	bool o=0;
	for(int i=0;i<a[x].size();i++) if(a[x][i]!=b[x][i]){
		c[x]+=a[x][i],c[x]+=b[x][i];
		if(o==0) c[x]+='0',p=i,o=1;
		else c[x]+=char(i-p+'0'),p=i;
	}
	s[x]=p;
//	cout<<a[x].size()<<"\n";   ,
}
bool bj(int x){
//	bool p=0;
	if(c[x].size()!=d.size()) return 0;
	for(int i=0;i<c[x].size();i++) if(c[x][i]!=d[i]) return 0;
	return 1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		c[i]=' ';
		cmp(i);
		s[i]=a[i].size()-s[i]-1;
//		cout<<s[i];
//		for(int j=0;j<=c[i].size();j++) cout<<c[i][j];
//		cout<<"\n";
	}
	for(int i=1;i<=q;i++){
		string x,y;
		d=' ';
		int ans=0;
		cin>>x>>y;
		int p=0,w=0;
		bool o=0;
		for(int j=0;j<x.size();j++) if(x[j]!=y[j]){
			d+=x[j],d+=y[j];
			if(o==0) d+='0',p=j,o=1;
			else d+=char(j-p+'0'),p=j;
		}
//		for(int j=0;j<=d.size();j++) cout<<d[j];" "<<x[k]<<cout<<a[j][k]<<"\n";cout<<a[j][t]<<" ";
//		cout<<d.size()<<"\n";  ,
		for(int j=1;j<=n;j++){
			bool e=0;
			if(bj(j)){
//				cout<<j<<" ";
				for(int k=p+s[j],t=a[j].size()-1;t>=0;k--,t--) if(a[j][t]!=x[k]){ e=1; break; }
				if(!e) ans++;
//				cout<<a[j][0]<<"\n";
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
