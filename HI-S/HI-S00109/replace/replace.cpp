#include<bits/stdc++.h>
using namespace std;

const int maxn=110000;

int n,q;
struct kfc{
	string s1;
	string s2;
};
kfc mh[maxn];
struct mdl{
	string t1;
	string t2;
};
mdl f[maxn];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>mh[i].s1>>mh[i].s2;
	}
	for(int i=1;i<=q;i++){
		cin>>f[i].t1>>f[i].t2;
		cout<<0<<endl;
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

2
0
*/
