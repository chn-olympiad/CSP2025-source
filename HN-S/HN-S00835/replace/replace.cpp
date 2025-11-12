#include<bits/stdc++.h>
using namespace std;
int n,q,num;
string a[200005],b[200005],x,y;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	while(q--){
		cin>>x>>y;
		int q=0,z=0;
		for(int i=0;i<x.size();i++){
			if(x[i]!=y[i]){
				if(q>0){
					z=i+1;
				}else{
					q=i+1;
				}
			}
		}
		for(int i=1;i<=n;i++){
			int mop=0,op;
			for(int j=0;j<x.size();j++){
				if(a[i][0]==x[j]){
					int jsq=0;
					for(int k=0;k<a[i].size();k++){
						if(a[i][k]!=x[j+k]){
							jsq++;
							break;
						}
					}
					if(jsq>0){
						continue;
					}else{
						mop++;
						op=j;
						break;
					}
				}
			}
			if(mop==0){
				continue;
			}
			int tu=0,qqq=0;
			for(int j=0;j<x.size();j++){
				if(j>=op&&j<=op+a[i].size()-1){
					if(b[i][qqq]!=y[j]){
						tu++;
						break;
					}
					qqq++;
				}else{
					if(x[j]!=y[j]){
						tu++;
						break;
					}
				}
			}
			if(tu>0){
				continue;
			}
			num++;
		}
		cout<<num<<endl;
		num=0;
	}
	return 0;
}
