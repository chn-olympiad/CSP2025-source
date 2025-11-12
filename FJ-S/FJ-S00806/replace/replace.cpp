#include<bits/stdc++.h>
using namespace std;
int n,q;
struct node{
	string x,y;
}o[200001];
map<string,string> m;
int ans=0;
//void dfs(string a,string b){
//	if(a==b){
//		ans++;
//		return;
//	}
//	for(int i=1;i<=n;i++){
//		string aa=a;
//		if(aa.find(o[i].x)!=EOF){
//			aa.replace(aa.find(o[i].x),o[i].x.size(),o[i].y);
//			dfs(aa,b);
//		}
//	}
//}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		string sx,sy;
		cin>>sx>>sy;
		m[sx]=sy;
		o[i].x=sx;
		o[i].y=sy;
	}
	while(q--){
		ans=0;
		string tx,ty;
		cin>>tx>>ty;
		if(tx.size()!=ty.size()){
			printf("0\n");
			continue;
		}
		if(m[tx]!=""&&m[tx]!=ty){
			printf("0\n");
			continue;
		}
		for(int i=1;i<=n;i++){
			string t=tx;
			if(t.find(o[i].x)!=EOF){
				t.replace(t.find(o[i].x),o[i].x.size(),o[i].y);
//				cout<<t<<endl;
				if(t==ty) ans++;
			}
		}
		printf("%d\n",ans);
//		printf("\n");
	}
	return 0;
}

