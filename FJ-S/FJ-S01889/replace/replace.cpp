#include<bits/stdc++.h>
using namespace std;
int n,q;
string x[200005],y[200005];
long long ans;
int main(){
	freopen("replace.in","r",stdin);	
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=q;++i){
		ans=0;
		string u,v;
		cin>>u>>v;
		if(u.size()!=v.size()){
			cout<<0<<endl;
		}
		else{
			for(int j=1;j<=n;++j){
				if(u.size()<x[j].size()){
					continue;
				}
				for(int k=0;k<=u.size()-x[j].size();++k){
					int f=1;
					for(int l=k;l<k+x[j].size();++l){
						if(x[j][l-k]!=u[l]){
							f=0;
							break;
						}
					}
					if(f){
						for(int l=0;l<k;++l){
							if(u[l]!=v[l]){
								f=0;
								break;
							}
						}
						if(f){			
							for(int l=k;l<k+x[j].size();++l){
								if(y[j][l-k]!=v[l]){
									f=0;
									break;
								}
							}
							if(f){
								for(int l=k+x[j].size();l<u.size();++l){
									if(u[l]!=v[l]){
										f=0;
										break;
									}
								}
								if(f){
									++ans;
								}
							}
						}
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);	
	return 0;
} 
