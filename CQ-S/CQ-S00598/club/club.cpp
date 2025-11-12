#include<bits/stdc++.h>
using namespace std;
const int N=100000+5;
int t;
int e[N][3];
int a[N],b[N],c[N],xc[N];
int cnt_a,cnt_b,cnt_c,cnt;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cnt_a=cnt_b=cnt_c=cnt=0;
		long long ans=0;
		for(int i=1;i<=n;i++){
			cin>>e[i][1]>>e[i][2]>>e[i][3];
			if(e[i][1]>=e[i][2] && e[i][1]>=e[i][3]){
				cnt_a++;
				a[cnt_a]=i;
				ans+=e[i][1];
				continue;
			}
			if(e[i][2]>=e[i][1] && e[i][2]>=e[i][3]){
				cnt_b++;
				b[cnt_b]=i;
				ans+=e[i][2];
				continue;
			}
			if(e[i][3]>=e[i][2] && e[i][3]>=e[i][1]){
				cnt_c++;
				c[cnt_c]=i;
				ans+=e[i][3];
			}
		}
		int Max=max({cnt_a,cnt_b,cnt_c});
		//cout<<cnt_a<<" "<<cnt_b<<" "<<cnt_c<<" "<<n/2<<endl;
		if(Max>n/2){
			int u=Max-n/2;
			if(Max==cnt_a){
				for(int i=1;i<=cnt_a;i++){
					int v=max(e[a[i]][2],e[a[i]][3]);
					xc[i]=e[a[i]][1]-v;
//					if(t==1 && v==e[a[i]][1]){
//						cout<<a[i]<<endl;
//					}
				}
				sort(xc+1,xc+cnt_a+1);
				for(int i=1;i<=u;i++){
					//if(t==1){
						//cout<<xc[i]<<endl;
					//}
					ans-=xc[i];
				}
			}else if(Max==cnt_b){
				for(int i=1;i<=cnt_b;i++){
					int v=max(e[b[i]][1],e[b[i]][3]);
					xc[i]=e[b[i]][2]-v;
				}
				sort(xc+1,xc+cnt_b+1);
				for(int i=1;i<=u;i++){
					ans-=xc[i];
				}
			}else if(Max==cnt_c){
				for(int i=1;i<=cnt_c;i++){
					int v=max(e[c[i]][2],e[c[i]][1]);
					xc[i]=e[c[i]][3]-v;
				}
				sort(xc+1,xc+cnt_c+1);
				for(int i=1;i<=u;i++){
					ans-=xc[i];
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
