//GZ-S00416 谭怡鹏 恒升高级中学
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;cin>>n>>q;
	string s[10010],ss[10010];
	for(int x=0;x<n;x++)cin>>s[x]>>ss[x];
	for(int x=1;x<=q;x++){
		int jg=0;
		string wt,tw;cin>>wt>>tw;
		if(wt.size()!=tw.size()){
			cout<<0<<endl;
		}
		else{	
			for(int y=0;y<n;y++){
				for(int z=0;z<wt.size();z++){
					if(wt[z]==s[y][0]&&tw[z]==ss[y][0]){
						int pp=0,l=z;
						bool oo=0;
						while(1){
							if(pp>=s[y].size()){
								bool kk=0;
								for(int u=l+1;u<wt.size();u++){
									if(wt[u]!=tw[u]){
										kk=1;
										break;
									}
								}
								for(int u=0;u<z;u++){
									if(wt[u]!=tw[u]){
										kk=1;
										break;
									}
								}
								if(kk)break;
								else{
									jg++;
									oo=1;
									break; 
								}
							}
							l++;
							pp++;
							if(wt[l]==s[y][pp]&&tw[l]==ss[y][pp]);
							else break;
						}
						if(oo)break;
					}	
				}
			}
			cout<<jg<<endl;
		}
	}
	return 0;
}

