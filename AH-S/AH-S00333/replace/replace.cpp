#include<iostream>
#include<cstdio>
using namespace std;
int n,q;
string a[200001],b[200001];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
	while(q--){
		long long ans=0;
		string x,y;
		cin>>x>>y;
		for(int i=1;i<=n;i++){
			string t=x;
			int pos=x.find(a[i]);
			while(pos!=-1){
				int sz=x.size();
				if(pos>0&&pos<sz-1){
					if(x.substr(0,pos)+b[i]+x.substr(pos+a[i].size(),x.size()-pos-a[i].size())==y){
						ans++;
					}
					x=x.substr(pos+a[i].size(),x.size()-pos-a[i].size());
				}else if(pos>0){
					if(x.substr(0,pos)+b[i]==y){
						ans++;
					}
					break;
				}else if(pos<sz-1){
					if(b[i]+x.substr(pos+a[i].size(),x.size()-pos-a[i].size())==y){
						ans++;
					}
					x=x.substr(pos+a[i].size(),x.size()-pos-a[i].size()).find(a[i]);
				}else break;
				pos=x.find(a[i]);
			}
			x=t;
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//RP++;
