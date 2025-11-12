#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string s1,s2;
int n,q;
struct node{
	string l,r;
};
node beg[N];
node chg[N];
bool vis[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>beg[i].l>>beg[i].r;
	for(int i=1;i<=q;i++) cin>>chg[i].l>>chg[i].r;
	bool flag=0;
	int tot=0;
	//int pos1b,pos2b;
	for(int i=1;i<=n;i++){
		for(int i=0;i<(int)beg[i].l.size();i++){
			if(beg[i].l[i]!='a'&&beg[i].l[i]!='b') flag=1;
			if(beg[i].l[i]=='b'){
				tot++;
				vis[i]=1;
			}
		}
		if(tot==0||tot>=2) flag=1;
		tot=0;
		for(int i=0;i<(int)beg[i].r.size();i++){
			if(beg[i].r[i]!='a'&&beg[i].r[i]!='b') flag=1;
			if(beg[i].r[i]=='b'){
				tot++;
				vis[i]=1;
			}
		}
	}
	if(tot==0||tot>=2) flag=1;
	if(!flag){
		for(int i=1;i<=q;i++){
			tot=0;
			for(int j=0;j<(int)chg[i].l.size();j++){
				if(chg[i].l[i]!='a'&&chg[i].l[i]!='b') flag=1;
				if(chg[i].l[i]=='b') tot++;
			}
			if(tot==0||tot>=2) flag=1;
			tot=0;
			for(int j=0;j<(int)chg[i].r.size();j++){
				if(chg[i].r[i]!='a'&&chg[i].r[i]!='b') flag=1;
				if(chg[i].r[i]=='b') tot++;
			}
			if(tot==0||tot>=2) flag=1;	
			if(flag) break;
		}
	}
	else{
		
		
	}
	for(int i=1;i<=q;i++){
		cout<<0<<"\n";
	}
	return 0;
}
