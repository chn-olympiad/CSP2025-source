#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string s[200001],ss[200001];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>ss[i];
	}
	for(int i=1;i<=q;i++){
		string t,tt;
		cin>>t>>tt;
		for(int j=1;j<=n;j++){
			int ls=s[j].length(),lt=t.length(),f; 
			for(int k=1;k<=lt;k++){
				if(s[j][k]==t[k]){
					f=k;
					if(k+ls-1<=n){
						for(int ii=k+1;ii<k+ls;ii++){
							if(s[j][ii]!=t[ii]){
								f=0;
								break;
							}else{
								f=ii;
							}
						}
					}
					if(f){
						if(lt==tt.length()){
							for(int ii=1;ii<=lt;ii++){
								if(ii>=k&&ii<=f){
									if(ss[j][ii]!=tt[ii]){
										f=0;
										break;
									}
								}else{
									if(t[ii]!=tt[ii]){
										f=0;
										break;
									}
								}
							}
							if(f){
								ans++;
							}
						}
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
