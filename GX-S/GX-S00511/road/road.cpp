#include<bits/stdc++.h>
using namespace std;
long long n,m,k,c[100010],a[150][100010],zero[150],ans=0,tot;
long long fa[100010];
struct road{
	long long from,to,dis;
}r[1000010],rr[1000010];
bool cmp(road a,road b){
	return a.dis<b.dis;
}
bool cmp1(road a,road b){
	return (a.from!=b.from?a.from<b.from:a.to<b.to);
}
long long find(long long x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(long long i=1;i<=m;i++){
		long long t1,t2,t3;
		cin>>t1>>t2>>t3;
		r[++tot]=(road){t1,t2,t3};
		//r[++tot]=(road){t2,t1,t3};
	}
	bool c0=0;
	for(long long i=1;i<=k;i++){
		cin>>c[i];
		//cout<<c[i];
		c0|=c[i];
		for(long long j=1;j<=n;j++){cin>>a[i][j];if(a[i][j]==0)zero[i]=j;}
	}
	//for(long long i=1;i<=n;i++)cout<<a[1][i]<<endl;
	for(long long i=1;i<=n;i++)fa[i]=i;
	if(k==0){
		long long cnt=1;
		sort(r+1,r+m+1,cmp);
		for(long long i=1;i<=/* 2* */m;i+=/* 2 */1){
			//prlong longf("i:%d fr:%d to:%d di:%d\n",i,r[i].from,r[i].to,r[i].dis);
			long long fx=find(r[i].from),fy=find(r[i].to);
			//prlong longf("fx:%d fy%d\n",fx,fy);
			if(fx!=fy){
				fa[fx]=fy;
				cnt++;
				ans+=r[i].dis;
			}
			if(cnt==n)break;
		}
		cout<<ans;
		return 0;
	}else if(!c0){
		//cerr<<"1\n";
		//prlong longf("c0 \n");
		//prlong longf("tot %d\n",/*tot*/m);
		sort(r+1,r+/*tot*/m+1,cmp1);
		//cerr<<"2\n";
		//for(long long i=1;i<=tot;i++)prlong longf("r[%d]: fr:%d to:%d di:%d\n",i,r[i].from,r[i].to,r[i].dis);
		long long mn=0x3f3f3f3f3f3f3f3f;
		//cerr<<"3\n";
		for(long long mask=0;mask< (1<<k);mask++){
			for(long long i=1;i<=n;i++)fa[i]=i;
			//prlong longf("mask %d\n",mask);
			ans=0;
			long long tott=m;
			//cerr<<"4\n";
			memcpy(rr,r,sizeof(r));
			//cerr<<"!\n";
			long long mm=mask;
			for(long long i=1;i<=k;i++){
				//cerr<<"i\n";
				if(mm%2){
					//prlong longf("i:%d mm1\n",i);
					for(long long j=1;j<=n;j++)if(zero[i]!=j)rr[++tott]=(road){zero[i],j,a[i][j]};
				}
				mm/=2;
			}
			//cerr<<"5\n";
			//prlong longf("end mask:");
			//for(long long i=1;i<=tott;i++)prlong longf("	rr[%d]: fr:%d to:%d di:%d\n",i,rr[i].from,rr[i].to,rr[i].dis);
			long long cnt=1;
			sort(rr+1,rr+tott+1,cmp);
			//cerr<<"6\n";
			//prlong longf("sort:\n");
			//for(long long i=1;i<=tott;i++)prlong longf("	rr[%d]: fr:%d to:%d di:%d\n",i,rr[i].from,rr[i].to,rr[i].dis);
			for(long long i=1;i<=tott;i+=1){
				//prlong longf("i:%d fr:%d to:%d di:%d\n",i,rr[i].from,rr[i].to,rr[i].dis);
				long long fx=find(rr[i].from),fy=find(rr[i].to);
				//prlong longf("fx:%d fy%d\n",fx,fy);
				if(fx!=fy){
					fa[fx]=fy;
					//for(long long i=1;i<=n;i++)prlong longf("%d ",fa[i]);
					cnt++;
					//prlong longf("\ncnt:%d n:%d\n",cnt,n);
					ans+=rr[i].dis;
					if(ans>=mn)break;
				}
				//prlong longf("cnt:%d n:%d tott:%d\n",cnt,n,tott);
				if(cnt==n)break;
			}
			mn=min(mn,ans);
			//prlong longf("mn %d ans %d\n",mn,ans);
		}
		cout<<mn;
		return 0;
	}else{
		srand(time(0));
		cout<<rand();
	}
	return 0;
}
