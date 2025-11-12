#include<bits/stdc++.h>
using namespace std;
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	string a[20005],b[20005];
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	while(q--){
		string xxx,yyy;
		cin>>xxx>>yyy;
		long long ans=0;
		if(xxx.size()!=yyy.size()){
			cout<<0<<"\n";
		}else{
			for(int i=1;i<=n;i++){
				if(xxx.size()<=a[i].size()){
					if(xxx==a[i] && yyy==b[i]){
						ans++;
					}
				}else{
					for(int j=0;j<xxx.size()-a[i].size();j++){
						if(xxx.substr(0,j)+b[i]+xxx.substr(j+a[i].size())==yyy){
							bool flag=1;
							for(int k=0;k<a[i].size();k++){
								if(xxx[j+k]!=a[i][k]){
									flag=0;
									break;
								}
							}
							if(flag){
								ans++;
							}
							
						}
					}
				}
				
			}
			cout<<ans<<"\n";
		}
		
	}
}
