#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int a;
	cin>>a;
	for(int v=0;v<a;v++){
		int o=0;
		int u;
		cin>>u;
		int l[u];
		int r[u];
		int x[u];
		for(int q=0;q<u;q++){
			cin>>l[q]>>r[q]>>x[q];
		}
		int p=0;
			if(u==2){
				o=max(max(max(l[0]+r[1],l[0]+x[1]),max(r[0]+l[1],r[0]+x[1])),max(x[0]+r[1],x[0]+l[1]));
			}else{
				for(int w=0;w<u;w++){
					if(r[w]>0||x[w]>0){
						p++;
						break;
					}
				}
				if(p==0){
					sort(l,l+u);
				}
				for(int e=u/2;e<u;e++){
					o+=r[e];
				}
			}
		cout<<o<<endl;
	}
	return 0;
}
