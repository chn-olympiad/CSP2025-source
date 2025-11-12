#include<bits/stdc++.h>
using namespace std;
struct re{
	string x,y;
}s[10001];
int pl[10001];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>s[i].x>>s[i].y;
	}
	while(q--){
		int ans=0,f=0;
		string a,b;
		cin>>a>>b;
		for(int i=0;i<a.size();i++){
			if(f==0){
				if(a[i]==b[i]){
					for(int j=0;j<n;j++){
						if(a[i]==s[j].x[pl[j]]&&a[i]==s[j].y[pl[j]]){
							pl[j]++;
						}
						else pl[j]=0;
					}
				}
				else{
					f=1;
					for(int j=0;j<n;j++){
						if(a[i]==s[j].x[pl[j]]&&b[i]==s[j].y[pl[j]])pl[j]++;
						else pl[j]=0;
						if(pl[j]==s[j].x.size())pl[j]=0;
					}
				}
			}
			else if(a[i]==b[i]){
				for(int j=0;j<n;j++){
					if(pl[j]==s[j].x.size()||pl[j]==0)continue;
					if(a[i]==s[j].x[pl[j]]&&b[i]==s[j].y[pl[j]])pl[j]++;
					else pl[j]=0;
				}
			}
			else{
				for(int j=0;j<n;j++){
					if(pl[j]==s[j].x.size())pl[j]=0;
					if(pl[j]==0)continue;
					if(a[i]==s[j].x[pl[j]]&&b[i]==s[j].y[pl[j]])pl[j]++;
					else pl[j]=0;
				}
			}
		}
		for(int i=0;i<n;i++){
			if(pl[i]==s[i].x.size())ans++;
		}
		cout<<ans<<endl;
	}
}
