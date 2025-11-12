#include<bits/stdc++.h>
using namespace std;
struct mem{
	int d[5];
};
bool operator < (mem a,mem b){
	return max(a.d[1],max(a.d[2],a.d[3]))-(a.d[1]+a.d[2]+a.d[3]-max(a.d[1],max(a.d[2],a.d[3]))-min(a.d[1],min(a.d[2],a.d[3])))>max(b.d[1],max(b.d[2],b.d[3]))-(b.d[1]+b.d[2]+b.d[3]-max(b.d[1],max(b.d[2],b.d[3]))-min(b.d[1],min(b.d[2],b.d[3])));
}
int n,ans;
mem a[100005]; 
priority_queue<mem> ve[5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T; cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		int si1=0;
		int si2=0;
		int si3=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].d[1],&a[i].d[2],&a[i].d[3]);
			if(a[i].d[1]>a[i].d[2]){
				if(a[i].d[1]>a[i].d[3]){
					ve[1].push(a[i]);
					si1++;
				}
				else{
					ve[3].push(a[i]);
					si3++;
				}
			}
			else{
				if(a[i].d[2]>a[i].d[3]){
					ve[2].push(a[i]);
					si2++;
				}
				else{
					ve[3].push(a[i]);
					si3++;
				}
			}
		}
		int xx,yy,zz;
		if(si1>si2){
			if(si1>si3){
				xx=1;
				if(si2>si3){
					yy=2;
					zz=3;
				}
				else{
					yy=3;
					zz=2;
				}
			}
			else{
				xx=3;
				yy=1;
				zz=2;
			}
		}
		else{
			if(si1>si3){
				xx=2;
				yy=1;
				zz=3;
			}
			else{
				zz=1;
				if(si2>si3){
					xx=2;
					yy=3;
				}
				else{
					xx=3;
					yy=2;
				}
			}
		}
		int xxx=max(max(si1,si2),si3);
//		cout<<xx<<yy<<zz<<endl;
		while(xxx>n/2){
			xxx--;
//			cout<<' '<<ve[xx].top().d[1]<<' '<<ve[xx].top().d[2]<<' '<<ve[xx].top().d[3]<<endl;
			if(ve[xx].top().d[yy]>ve[xx].top().d[zz]){
				ve[yy].push(ve[xx].top());
				ve[xx].pop();
			}
			else{
				ve[zz].push(ve[xx].top());
				ve[xx].pop();
			}
		}
		for(int i=1;i<=3;i++){
			while(!ve[i].empty()){
				ans+=ve[i].top().d[i];
				ve[i].pop();
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 