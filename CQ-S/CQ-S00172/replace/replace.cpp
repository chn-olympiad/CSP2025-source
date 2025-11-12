//10pts
//please mark upper
#include<bits/stdc++.h>
using namespace std;
map<string,map<string,bool> >t;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		string a,b;
		cin>>a>>b;
		t[a][b]=1;
	}
	for(int i=1;i<=m;i++){
		string a,b;
		cin>>a>>b;
		int topl=0,topr=n;
		for(int i=0;i<a.length();i++){
			if(a[i]!=b[i]){
				topr=i;
			}
		}
		for(int i=a.length()-1;i>=0;i--){
			if(a[i]!=b[i]){
				topl=i;
			}
		}
		int cnt=0;
		for(int l=0;l<=topl;l++){
			for(int len=topr-l+1;l+len-1<a.length();len++){
				if(t[a.substr(l,len)][b.substr(l,len)]){
					cnt++;
				}
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a

4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
