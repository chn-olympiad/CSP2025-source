#include<bits/stdc++.h>
using namespace std;
const int N=1e6+50; 
int t,n,con,a1,b1;
bool flag=1;
bool flag1=1;
bool a[N];
struct cy{
	int aa,bb,cc;
}c[3*N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>c[i].aa>>c[i].bb>>c[i].cc;
			if(!c[i].bb) flag=0;
			if(!c[i].cc) flag=0,flag1=0;
		}
		if(flag){
			for(int i=1;i<=n;i++){
				int ans=-1;
				int dex;
				if(!a[i]){
					if(a[i]>ans){
						ans=a[i],dex=i;
					}
				}
				con+=ans,a[dex]=1;
			}
			cout<<con;
			return 0;
		}
		if(flag1){
		for(int i=1;i<=n;i++){
			con+=max(c[i].aa,c[i].bb);
		}
		cout<<con;
		return 0;
		}
	}
}
