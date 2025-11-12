#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
string a[N],b[N]; 
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	while(q--){
		string w,g;
		cin>>w>>g;
		int ans=0,lx=-1;
		for(int i=1;i<=n;i++){
			for(int j=0,x=w.find(a[i],j);x<=w.size();x=w.find(a[i],++j)){
				if(x!=lx||lx==-1){
					string e;
					for(int o=0;o<x;o++){
						e+=w[o];
					}e+=b[i];
					for(int o=x+a[i].size();o<w.size();o++){
						e+=w[o];
					}
					if(e==g)ans++;
					lx=x;
				}
			}
		}
		printf("%d\n",ans);
	}
	
	
}
