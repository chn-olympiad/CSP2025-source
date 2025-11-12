#include <bits/stdc++.h>
using namespace std;
int n,q;
string a[200005],b[200005];
bool che(string mb,string mq,string bh,string wl,int sta){
	for(int i=sta,j=0;i<sta+mb.size();i++,j++){
		if(mq[i]!=mb[j]) return false;
	}
	for(int i=sta,j=0;i<sta+mb.size();i++,j++){
		mq[i]=bh[j];
	}
	if(mq!=wl) return false;
	else return true;
}
int da=0;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	} 
	for(int i=1;i<=q;i++){
		string qa,qb;
		cin>>qa>>qb;
		da=0;
		if(qa.size()!=qb.size()){
			cout<<0<<endl;
			continue;
		}
		for(int j=1;j<=n;j++){
			int u=a[j].size();
			if(u>qa.size()) continue;
			for(int k=0;k<=qa.size()-u;k++){
				da+=(che(a[j],qa,b[j],qb,k)) ;
			} 
		}
		cout<<da<<endl;
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
