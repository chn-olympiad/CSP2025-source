#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long d[N],e[N],f[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		int tota=0,totb=0,totc=0;
		long long ans=0;
		for(int i=1;i<=n;i++){
			int A,B,C;
			cin>>A>>B>>C;
			if(A>=B&&A>=C){
				ans+=A;
				tota++;
				d[i]=1;
				e[i]=min(A-B,A-C);
				continue;
			}
			if(B>=A&&B>=C){
				ans+=B;
				totb++;
				d[i]=2;
				e[i]=min(B-A,B-C);
				continue;
			}
			if(C>=A&&C>=B){
				ans+=C;
				totc++;
				d[i]=3;
				e[i]=min(C-A,C-B);
				continue;
			}
		}
		int hh=0,cnt=0;
		if(tota>n/2){
			for(int i=1;i<=n;i++){
				if(d[i]==1){
					hh++;
					f[hh]=e[i];
				}
			}
			cnt=tota-n/2;
		}
		if(totb>n/2){
			for(int i=1;i<=n;i++){
				if(d[i]==2){
					hh++;
					f[hh]=e[i];
				}
			}
			cnt=totb-n/2;
		}
		if(totc>n/2){
			for(int i=1;i<=n;i++){
				if(d[i]==3){
					hh++;
					f[hh]=e[i];
				}
			}
			cnt=totc-n/2;
		}
		sort(f+1,f+hh+1);
		for(int i=1;i<=cnt;i++){
			ans-=f[i];
		}
		cout<<ans<<'\n';
	}
}
