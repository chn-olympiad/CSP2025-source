#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define N 200005
using namespace std;
int n,q,ans;
string s[N],t[N],x,y;
bool f;
int main(){
	IOS;
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i]>>t[i];
	for(int i=1;i<=q;i++){
		cin>>x>>y,ans=0;
		for(int j=1;j<=n;j++){
			for(int l=0;l<x.size();l++){
				f=0;
				for(int r=0;r<s[j].size();r++)
					if(x[l+r]!=s[j][r]){f=1;break;}
				if(f==0){
					string tx="",xx="",yy="";
					for(int r=0;r<x.size();r++){
						if(r<l)tx+=x[r],xx+=x[r];
						else if(r<l+s[j].size())tx+=t[j][r-l];
						else tx+=x[r],yy+=x[r];
					}if(tx==y&&(xx!=yy))ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
