#include<bits/stdc++.h>
using namespace std;
int n,m,ans,f;
string a[200005],b[200005],x,y;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i]>>b[i];
	}
    while(m--){
    	ans=0;
    	cin>>x>>y;
    	for(int i=1;i<=n;i++){
    		for(int j=0;j<x.size();j++){
    			if(x[j]==a[i][0]){
    				f=0;
    				for(int l=0;l<a[i].size();l++){
    					if(x[j+l]!=a[i][l]){
    						f=1;
    						break;
						}
					}
					if(f==0){
					for(int l=0;l<x.size();l++){
						if(l>=j&&l<=j+a[i].size()-1){
							if(b[i][l-j]!=y[l]){
							f=1;	
							break;
							}
						}else{
							if(x[l]!=y[l]){
							f=1;
							break;	
							}
						}
					}
					if(f==0) ans++;	
					}
				}
			}
		}
		cout<<ans<<endl;
	}



	return 0;
}

