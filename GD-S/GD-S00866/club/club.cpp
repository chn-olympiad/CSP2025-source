#include<bits/stdc++.h>
using namespace std;
long long a,b,c[100005][5],d[5],e,f[100005],g[100005];
priority_queue<long long,vector<long long>,greater<long long> >h;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&a);
	for(long long i=1;i<=a;i++){
		scanf("%lld",&b);
		for(long long j=1;j<=b;j++){
			scanf("%lld %lld %lld",&c[j][1],&c[j][2],&c[j][3]);
			if(c[j][1]>c[j][2]&&c[j][1]>c[j][3]){
				d[1]++;
				e+=c[j][1];
				f[j]=1;
			}
			else if(c[j][2]>c[j][3]){
				d[2]++;
				e+=c[j][2];
				f[j]=2;
			}
			else{
				d[3]++;
				e+=c[j][3];
				f[j]=3;
			}
			sort(c[j]+1,c[j]+4);
			g[j]=c[j][3]-c[j][2];
		}
		if(d[1]>b/2){
			for(long long j=1;j<=b;j++){
				if(f[j]==1){
					h.push(g[j]);
				}
			}
			for(long long j=1;j<=d[1]-b/2;j++){
				e-=h.top();
				h.pop();
			}
		}
		if(d[2]>b/2){
			for(long long j=1;j<=b;j++){
				if(f[j]==2){
					h.push(g[j]);
				}
			}
			for(long long j=1;j<=d[2]-b/2;j++){
				e-=h.top();
				h.pop();
			}
		}
		if(d[3]>b/2){
			for(long long j=1;j<=b;j++){
				if(f[j]==3){
					h.push(g[j]);
				}
			}
			for(long long j=1;j<=d[3]-b/2;j++){
				e-=h.top();
				h.pop();
			}
		}
		printf("%lld\n",e);
		d[1]=d[2]=d[3]=0;
		e=0;
		for(long long j=1;j<=b;j++){
			f[j]=g[j]=0;
		}
		while(h.size()){
			h.pop();
		}
	}
	return 0;
}
