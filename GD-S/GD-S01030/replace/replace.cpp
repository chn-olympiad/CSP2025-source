#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>
using namespace std;
int n,q;
string a[100005],b[100005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=q;i++){
		string s,t;
		cin>>s>>t;
		int ans=0;
		for(int i=1;i<=n;i++){
			int last=0;
			while(s.find(a[i],last)!=-1){
				last=s.find(a[i],last);
				string to=s;
				to.erase(last,a[i].size());
				to.insert(last,b[i]);
				if(to==t)ans++; 
				last++;
			}
		}
		printf("%d\n",ans);
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
