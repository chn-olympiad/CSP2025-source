#include <bits/stdc++.h>
using namespace std;
int ans=0,a[1000],b[1000],c[1000];
int n;
void as(int id1,int id2,int id3,int mian,int cnt){
	if(cnt==n+1){
		ans=max(ans,mian);
	}
	if(id1+1<=n/2){
		as(id1+1,id2,id3,mian+a[cnt],cnt+1);
	}
	if(id2+1<=n/2){
		as(id1,id2+1,id3,mian+b[cnt],cnt+1);
	}
	if(id3+1<=n/2){
		as(id1,id2,id3+1,mian+c[cnt],cnt+1);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		if(n>=30){
			int idb=true,idc=true;
			for(int i=1;i<=n;i++){
				scanf("%d%d%d",&a[i],&b[i],&c[i]);
			}
			int num=0;
			sort(a+1,a+1+n);
			for(int i=1;i<=n/2;i++){
				num+=a[i];
			}
			cout<<num;
			continue;
		}
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
		}
		as(0,0,0,0,1);
		cout<<ans<<"\n";
		ans=0;
	}
}
