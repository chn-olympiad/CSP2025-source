#include<bits/stdc++.h>
using namespace std;
int n,q;
struct point{
	string s1,s2;
}a[200005],b[200005];
string t1,t2;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].s1>>a[i].s2;
	}
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		int ans=0;
		for(int j=1;j<=n;j++){
			bool xjh=true;
			for(int k=0;k<t1.size();k++){
				if(a[j].s1[0]==t1[k]){
					int p=k;
					bool flag=true;
					for(int x=0;x<a[j].s1.size();x++){
						if(a[j].s1[x]!=t1[p]) {
							flag=false;
							break;
						}
						if(t2[p]!=a[j].s2[x]){
							flag=false;
							break;
						}
						p++;
					}
					for(int xjhl=0;xjhl<k;xjhl++){
						if(t1[xjhl]!=t2[xjhl]){
							flag=false;
							break;
						}
					}
					for(;p<t1.size();p++){
						if(t1[p]!=t2[p]){
							flag=false;
							break;
						}
					}
					if(flag==true) {
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
}
