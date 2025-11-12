#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{
	int u;
	string s;
}tir[N*26][26];
int tot=1;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		string s,t;
		cin>>s>>t;
		int p=1;
		for(int j=0;j<s.size();j++){
			if(tir[p][s[j]-'a'].u==0){
				tir[p][s[j]-'a'].u=(++tot);
			}
			if(j+1==s.size()) tir[p][s[j]-'a'].s=t;
			p=tir[p][s[j]-'a'].u;
		}
	}
	for(int i=1;i<=m;i++){
		int ret=0;
		string s,t;
		cin>>s>>t;
		if(s.size()!=t.size()){
			cout<<"0\n";
			continue;
		}
		for(int j=0;j<s.size();j++){
			if(j!=0&&s[j-1]!=t[j-1]) continue;
			int p=1,l=j;
			while(tir[p][s[l]-'a'].u!=0){
				if(tir[p][s[l]-'a'].s!=""){
//					cout<<j<<","<<l<<"\n";
					bool flag=true;
					string w=tir[p][s[l]-'a'].s;
					for(int x=j;x<=l;x++){
//						cout<<"="<<w[x-j]<<","<<t[x]<<"\n";
						if(w[x-j]!=t[x]){
							flag=false;
							break;
						}
					}
//					cout<<flag<<"-\n";
					for(int x=l+1;x<s.size();x++){
//						cout<<"="<<s[x]<<","<<t[x]<<"\n";
						if(s[x]!=t[x]){
							flag=false;
							break;
						}
					}
//					cout<<flag<<"\n";
					if(flag) ret++;
				}
				p=tir[p][s[l]-'a'].u;
				l++;
			}
		}
		cout<<ret<<"\n";
	}
	return 0;
}
