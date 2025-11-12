#include<bits/stdc++.h>
using namespace std;
int n,q,num;
string a1[200005],a2[200005],x,y;
int find(string a,string b){
	for(int i=0;i<=a.size()-b.size();i++){
		if(a.substr(i,b.size()) == b){
			return i;
		}
	}
	return -1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>a1[i]>>a2[i];
	}
	while(q--){
		cin>>x>>y;
		for(int i=1;i<=n;i++){
			int c1=find(x,a1[i]);
			int c2=find(y,a2[i]);
			if(c1!=-1&&c2!=-1){
				if(x.substr(0,c1)==y.substr(0,c2)
				&&x.substr( c1+a1[i].size() , x.size()-(c1+a1[i].size()) )
				==y.substr( c2+a2[i].size() , y.size()-(c2+a2[i].size()) )){
					num++;
				}
			}
		}
		printf("%d\n",num);
	}
	return 0;
}
