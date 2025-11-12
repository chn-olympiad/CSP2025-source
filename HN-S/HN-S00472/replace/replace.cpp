#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct P{
	string x,y;
};
P a[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	long long n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
	}
	while(q--){
		string x,y;
		cin>>x>>y;
		long long cnt=0,Max=0;
		for(int i=0;i<x.size();i++){
			/*
			那么什么时候才可以替换？
4 3
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex

aaaa bbbb

aaaa abbb
0
			*/
			
			if(x[i]!=y[i]){
				Max=max(cnt,Max);
				cnt=0;
			}else{
				cnt++;
			}
		}
		cout<<Max<<"\n";
	}
	return 0;
}
