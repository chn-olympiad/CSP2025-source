#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
struct str{
	string a,b;
}nn[200000],qq[200000];
void zh(int x){
	for(int i=0;i<n;i++){
		if(nn[i].a==qq[x].a&&nn[i].b==qq[i].b){
			ans++;
		}else{
			string t;
			int k=0,f=0,s=-1;
			for(int j=0;j<qq[j].a.size();j++){
				if(k>nn[i].a.size()){
					s=j-1;
					f=1;
					break;
				}
				if(qq[x].a[j]==nn[i].a[k]){
					k++;
					t+=qq[x].a[j];
				}else{
					k=0;
					t="";
				}
			}
			if(f==1){
					for(int i=s-nn[i].a.size();i>=0;i--){
						if(qq[x].a[i]!=qq[x].b[i]){
							f=0;
							break;
						}
					}
					if(f==1){
						for(int i=s;i<qq[x].b.size();i++){
							if(qq[x].a[i]!=qq[x].b[i]){
								f=0;
								break;
							}
						}
						if(f==1){
							for(int i=s-k;i<s;i++){
								if(nn[i].b[i]!=qq[x].b[i]){
									f=0;
									break;
								}
							}
							if(f==1) ans++;
						}
					}
				}
			}
		}
	}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++) cin>>nn[i].a>>nn[i].b;
	for(int i=0;i<q;i++){
		cin>>qq[i].a>>qq[i].b;
		zh(i);
	}
	cout<<ans+1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
