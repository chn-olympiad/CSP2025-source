#include <bits/stdc++.h>
using namespace std;
struct replace{
	string a,b;
}al[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>al[i].a>>al[i].b;
	}
	while(q--){
		string aa,bb;
		cin>>aa>>bb;
		int na=aa.size(),nb=bb.size(),nn=al[i].a.size();
		for(int i=1;i<=n;i++){
			int fa=aa.find(al[i].a),fb=bb.find(al[i].b)
			if(fa<=na&&fb<=nb){
				for(int i=fa;i<=nn;i++){
					aa[i]=aa[i-(fa-1)];
				}
			}
		}
	}
	return 0;
}

