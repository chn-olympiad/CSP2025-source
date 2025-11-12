#include<bits/stdc++.h>
using namespace std;

const int N=1e5+3;
struct ct{
	int num,id;
}g[N][3],idd[N];
struct ct1{
	int num,id;
}sortt[3];
bool cmp(ct1 a,ct1 b){
	if(a.num==b.num )return a.id <b.id ;
	else return a.num>b.num;
}
bool cmp2(ct a,ct b){
	if(a.num==b.num )return a.id <b.id ;
	else return a.num>b.num;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	int t,n,a,b,c;
	cin>>t;
	while(t--){
		long long ans=0;
		int cnt1=0,cnt2=0;
		int cnt[3]{0,0,0};
		cin>>n;
		for(int i=1;i<=n;i++){
		cin>>a>>b>>c ;
		sortt[0].num=a,sortt[0].id=1;
		sortt[1].num=b,sortt[1].id=2,
		sortt[2].num=c,sortt[2].id=3;
		sort(sortt,sortt+3,cmp);
		for(int j=0;j<=2;j++){
			g[i][j].num =sortt[j].num ;
			g[i][j].id =sortt[j].id ;
		}
		idd[i].num=sortt[0].num;
		idd[i].id=i;
		}
		sort(idd+1,idd+1+n,cmp2);
	    for(int i=1;i<=n/2;i++){
	    	 ans+=idd[i].num;
	    	 cnt[g[idd[i].id][0].id]++;
		}
	    for(int i=n/2+1;i<=n;i++){
	         for(int j=0;j<=2;j++){
	         	int id=idd[i].id;
	         	int pos=g[id][j].id ;
	         	if(cnt[pos]>=n/2)continue;
	         	else{
	         		cnt[pos]++;
	         		ans+=g[id][j].num;
	         		break;
				 }
			 }
		}
		cout<<ans<<"\n";
	}
		return 0;
}