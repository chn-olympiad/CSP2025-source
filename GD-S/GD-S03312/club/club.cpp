#include<bits/stdc++.h>
using namespace std;
long long t,n,jk[4],ans;
struct node{
	int a,b,c;
	int v;
}d[100005];
struct h{
	int bh,sh;
}k[300005];
bool cmp(h a,h b){
	return a.sh>b.sh;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","W",stdout);
	cin>>t;
	while(t--){
		ans=0;
		memset(d,0,sizeof(d));
		memset(jk,0,sizeof(jk));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>d[i].a>>d[i].b>>d[i].c;
			k[i*3-2].bh=i*3-2;
			k[i*3-1].bh=i*3-1;
			k[i*3].bh=i*3; 
			k[i*3-2].sh=d[i].a;
			k[i*3-1].sh=d[i].b;
			k[i*3].sh=d[i].c;
		}
		sort(k+1,k+n*3+1,cmp);
		for(int i=1;i<=3*n;i++){
			int s=(k[i].bh+3)%3,w=(k[i].bh+2)/3;
			if(d[w].v==0&&jk[s]+1<=n/2){
				jk[s]++;
				ans+=k[i].sh;
				d[w].v=1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
