#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int T;
int n;
int a[N][4];
int w[4];
priority_queue <int,vector<int> ,greater<int> > p[4]; 
ll cnt;
struct sb{
	int idd,s;
}ma;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		cnt=0;
		for(int i=1;i<=3;i++){
			w[i]=0;
			while(p[i].empty()==0) p[i].pop();
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
			}
			ma.s=0;
			for(int j=1;j<=3;j++){
				if(a[i][j]>ma.s){
					ma.s=a[i][j];
					ma.idd=j;
				}
			}
			w[ma.idd]++;
			//cout<<ma.idd<<"\n";
			cnt+=a[i][ma.idd];
			//v[ma.idd].push_back(v);
			if(ma.idd==1){
				ma.s=min(a[i][1]-a[i][2],a[i][1]-a[i][3]);
			}else if(ma.idd==2){
				ma.s=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
			}else{
				ma.s=min(a[i][3]-a[i][2],a[i][3]-a[i][1]);
			}
			p[ma.idd].push(ma.s);
			
		}
		int k;
		for(int i=1;i<=3;i++){
			while(w[i]>n/2){
				
				w[i]--;
				k=p[i].top();
				cnt-=k;
				p[i].pop();
			}
		}
		printf("%lld\n",cnt);
	}
	return 0;
} 
