#include<bits/stdc++.h>
using namespace std;
int n,m;
string s[2001],u[2001],s1[2001],u1[2001],ss,uu,c[2001],ww[2001];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ss>>uu;
		int l=ss.size();
		int k=l,l1=-1;
		for(int j=0;ss[j]==uu[j];j++) s[i]+=ss[j],l1=j;
		for(int j=l-1;ss[j]==uu[j];j--) k=j;
		for(int j=k;j<l;j++) u[i]+=ss[j];
		for(int j=l1+1;j<k;j++) c[i]+=ss[j],ww[i]+=uu[j];
	}
	while(m--){
		string e,ik;
		cin>>ss>>uu;
		int l=ss.size(),i1=0,j1=l-1,st=0;
		while(ss[i1]==uu[i1])i1++;
		while(ss[j1]==uu[j1])j1--;
		for(int i=1;i<=i1;i++) s1[i]=ss[i1-i]+s1[i-1];
		for(int i=i1;i<=j1;i++) e+=ss[i],ik+=uu[i];
		for(int i=j1+1;i<l;i++) u1[i-j1]=u1[i-j1-1]+ss[i];
		for(int i=1;i<=n;i++)
			if(e==c[i]&&ik==ww[i]){
				int l1=s[i].size();
				int l2=u[i].size();
				if(s1[l1]==s[i]&&u1[l2]==u[i]) st++;
			}
		cout<<st<<"\n";
	}
}
