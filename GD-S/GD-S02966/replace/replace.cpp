#include<bits/stdc++.h>
using namespace std;
int n,m;
string x,y;
struct data{
	string k,z;
	int l,v,w;
}a[200005],b[200005];
bool cmp(data p,data q){
	return p.l<q.l;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].k>>a[i].z;
		a[i].l=a[i].k.size();
		int l=-1,r=-1;
		string s1=a[i].k,s2=a[i].z;
		for(int j=0;j<a[i].l;j++){
			if(s1[j]!=s2[j]){
				l=j;
				break;
			}
		}
		for(int j=a[i].l-1;j>=0;j--){
			if(s1[j]!=s2[j]){
				r=j;
				break;
			}
		}
		if(l==-1||r==-1){
			b[i].k=a[i].k,b[i].z=a[i].z,b[i].l=a[i].l;
		}
		for(int j=l;j<=r;j++){
			b[i].k+=s1[j],b[i].z+=s2[j];
		}
		b[i].l=b[i].k.size();
		b[i].v=l,b[i].w=r;
	}
	for(int i=1;i<=m;i++){
		int ans=0;
		cin>>x>>y;
		if(x.size()!=y.size()){
			cout<<0<<"\n";
			continue;
		}
		int l=-1,r=-1;
		string s1=x,s2=y,s3,s4;
		s3=s4="";
		for(int j=0;j<x.size();j++){
			if(s1[j]!=s2[j]){
				l=j;
				break;
			}
		}
		for(int j=x.size()-1;j>=0;j--){
			if(s1[j]!=s2[j]){
				r=j;
				break;
			}
		}
		for(int j=l;j<=r;j++){
			s3+=s1[j],s4+=s2[j];
		}
		for(int j=1;j<=n;j++){
			if(b[j].k==s3&&b[j].z==s4&&a[j].l<=x.size()&&x.find(a[j].k)!=-1&&y.find(a[j].z)!=-1){
				ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
