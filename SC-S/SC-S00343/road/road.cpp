#include<bits/stdc++.h>
using namespace std;
int l[100005],r[1000005],p[1000005],qqq[1000005],nc[15];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,ans=0;
	for(int i=1;i<=m;i++){
		cin>>l[i]>>r[i]>>p[i];
	}
	for(int i=1;i<=n;i++){
		qqq[i]=9999999;
		for(int j=1;j<=m;j++){
			if(l[j]==i){
				if(p[j]<=qqq[i]) qqq[i]=p[j];
			}
			if(r[j]==i){
				if(p[j]<=qqq[i]) qqq[i]=p[j];
			}
		}
	}
	for(int i=1;i<=n;i++){
		ans+=qqq[i];
	}
	cout<<ans;
	return 0;
}