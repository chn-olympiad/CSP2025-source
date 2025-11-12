#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int ji=20010;
// ji->0 num=index-ji
struct pt{
	int a,b,c;
}p[100005];
int T,n;
int haxi[40050];
// haxi: b->c cost
ll ans;
bool cmp(pt p1,pt p2){
	if(p1.a==p2.a) return p1.b-p1.c < p2.b-p2.c;//
	return p1.a-p1.b > p2.a-p2.b;
}
bool check_rg(int cnum,int bnum){
	return cnum<n/2 && bnum;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		scanf("%d",&n);
		ll sumb=0;
		for(int i=1;i<=n;i++){
			cin>>p[i].a>>p[i].b>>p[i].c;
			haxi[ji+p[i].b-p[i].c]++;
			sumb+=p[i].b;
		}
		sort(p+1,p+n+1,cmp);
		ll suma=0;
		map<int,int> mp;
		for(int anum=0;anum<=n/2;anum++){
			suma+=p[anum].a;
			sumb-=p[anum].b;
			ll tans=sumb;
			
			if(anum>=1) haxi[ ji + p[anum].b - p[anum].c ]--;
			
			int bnum=n-anum,cnum=0,ind=0,flag=0;
			//flag 0:- 1:+/0
			
			while(!haxi[ind]&&ind<=40020) ind++;
			if(ind-ji>=0) flag=1;
			
			int cont=0;
			while(check_rg(cnum,bnum)&&!flag || bnum>n/2){
				tans-=ind-ji;
				cont++;
				bnum--;cnum++;
				
				if(cont==haxi[ind]){
					cont=0;
					
					while(!haxi[ind]&&ind<=40020) ind++;
					
					if(ind==40020) break;
					if(ind-ji>=0) flag=1;
				}
			}
			tans+=suma;
			ans=max(ans,tans);
		}
		printf("%lld\n",ans);
		for(int i=0;i<=40025;i++) haxi[i]=0;
	}
	return 0;
}
