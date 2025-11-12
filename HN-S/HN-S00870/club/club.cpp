#include<bits/stdc++.h>
using namespace std;
int maxn,a[114514],b[114514],c[114514];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int aq=n/2,bq=n/2,cq=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			int s=max(a[i],max(b[i],c[i]));
			if(s==a[i]){
				if(aq==0){
					if(cq==0) s=b[i];
					if(bq==0) s=c[i];
					else s=max(b[i],c[i]);
				}
				maxn+=s;
			}else if(s==b[i]){
				if(bq==0){
					if(cq==0) s=a[i];
					if(aq==0) s=c[i];
					else s=max(a[i],c[i]);
				}
				maxn+=s;
			}else if(s==c[i]){
				if(bq==0){
					if(bq==0) s=a[i];
					if(aq==0) s=b[i];
					else s=max(a[i],b[i]);
				}
				maxn+=s;
			}
		}
		cout<<maxn<<endl;
		maxn=0;
	}
}
