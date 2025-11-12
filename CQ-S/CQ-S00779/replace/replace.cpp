#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int m,n,cnt;
string a,s;
struct node{
	string a,s,d,f;
}q[2*N];
void z(string x,string y){
	string w="",ww="",e="",ee="";
	int o=0;
	for(int i=0;i<x.size();i++){
		if(x[i]!=y[i]&&o==0) q[++cnt].a=w,o=1,w="";
		if(o==1){
			w+=x[i];
			ww+=y[i];
			if(x[i]!=y[i]) e+=w,ee+=ww,w="",ww="";
		}
		else w+=x[i];
	}
	if(o==0) q[++cnt].a=w;
	q[cnt].s=e;
	q[cnt].d=ee;
	q[cnt].f=w;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		cin>>a>>s;
		z(a,s);
	}
	for(int i=1;i<=n;i++){
		cin>>a>>s;
		z(a,s);
		int o=0,sum=0;
		for(int j=1;j<=cnt-i;j++){
			o=0;
			if(q[cnt].a.size()<q[j].a.size()||q[cnt].f.size()<q[j].f.size()||q[cnt].s!=q[j].s||q[cnt].d!=q[j].d) continue;
			for(int r=1;r<=q[j].a.size();r++){
				if(q[cnt].a[q[cnt].a.size()-r]!=q[j].a[q[j].a.size()-r]) o=1;
			}
			for(int r=1;r<=q[j].f.size();r++){
				if(q[j].f[r]!=q[cnt].f[r]) o=1;
			}
			if(o!=1) sum++;
		}
		cout<<sum<<endl;
	}
	return 0;
}
