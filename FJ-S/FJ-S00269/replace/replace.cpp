#include<bits/stdc++.h>
using namespace std;
string u[200005];
string v[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	scanf("%d%d\n",&n,&m);
	for(int i=0;i<n;i++){
		cin>>u[i]>>v[i];
	}
	int t;
	string x,y;
	while(m--){
		cin>>x>>y;
		if(x.size()-y.size()){
			printf("0\n");
			continue;
		}
		int s=0;
		for(int i=0;i<n;i++){
			int p=x.find(u[i]);
			if(p==-1){
				continue;
			}
			u[n]=x.substr(0,p)+v[i];
			t=p+v[i].size();
			if(t<x.size()){
				u[n]+=x.substr(t,5000005);
			}
			if(u[n]==y){
				s++;
			}
		}
		printf("%d\n",s);
	}
}
