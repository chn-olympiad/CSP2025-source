#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	string s,v;
}a[200050],b[200050];
int th(string s1,string s2,string s3,string s4){
	int aq=0;
	string s;
	for(int i=0;i<s2.size();i++){
		if(s2[i]==s1[0]&&i+s1.size()<=s2.size()){
			s=s2;
			int ks=1;
			for(int j=0;j<s1.size();j++){
				s[i+j]=s4[j];
				if(s1[j]!=s2[i+j]){
					ks=-1;
					break;
				} 
				else{
					if(s3[i+j]!=s4[j]){
						ks=-1;
						break;
					} 
				}
			}
			if(ks==1&&s==s3){
				aq++;
			}
		}
	}
	return aq;
}
void yzc(string x,string y){
	if(x.size()!=y.size()||x==y){
		cout<<0<<endl;
		return ;
	}
	string su,vm;
	int t=0,sum=0,f[n+1];
	memset(f,0,sizeof(f));
	for(int i=0;i<x.size();i++){
		if(x[i]!=y[i]){
			su[t]=x[i];
			vm[t]=y[i];
			t++;
		}
	}
	for(int i=1;i<=n;i++){
		if(su==a[i].s&&vm==a[i].v){
			sum++;
			f[i]=1;
		}
	}
	for(int i=1;i<=n;i++){
		if(f[i]==0&&a[i].s.size()<=x.size()){
			sum+=th(a[i].s,x,y,a[i].v);
			f[i]=1;
		}
	}
	cout<<sum<<endl;
	return ;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].s>>a[i].v;
	}
	for(int i=1;i<=m;i++){
		cin>>b[i].s>>b[i].v;
		yzc(b[i].s,b[i].v);
	}
	return 0;
}  
