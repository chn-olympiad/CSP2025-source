#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,T;
struct node{
	int num,x,y,z;
}a[N];
struct Node{
	int id,val;
};
int b[N][3];
vector<Node>x,y,z;
bool cmp(Node A,Node B){
	return A.val-b[A.id][1]>B.val-b[B.id][1];
}
void solve(){
	scanf("%d",&n);
	int lim=n/2,cntx=0,cnty=0,cntz=0;
	x.clear(),y.clear(),z.clear();
	for(int i=1;i<=n;++i){
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		b[i][0]=a[i].x,b[i][1]=a[i].y,b[i][2]=a[i].z;
		sort(b[i],b[i]+3);
//		for(int j=0;j<=2;++j)printf("%d ",b[i][j]);
//		cout<<endl;
		if(a[i].x>=a[i].y&&a[i].x>=a[i].z)x.push_back({i,a[i].x}),cntx++;
		else{
			if(a[i].y>=a[i].z&&a[i].y>=a[i].x)y.push_back({i,a[i].y}),cnty++;
			else{
				if(a[i].z>=a[i].y&&a[i].z>=a[i].x)z.push_back({i,a[i].z}),cntz++;
			}
		}
	}
	long long ans=0;
	for(int i=0;i<cntx;++i)ans+=x[i].val;
	for(int i=0;i<cnty;++i)ans+=y[i].val;
	for(int i=0;i<cntz;++i)ans+=z[i].val;
//	printf("X:%d Y:%d Z%d\n",cntx,cnty,cntz);
	if(cntx>lim){
//		printf("This x\n");
		sort(x.begin(),x.end(),cmp);
//		for(int i=0;i<cntx;++i)printf("%d ",x[i].val);
//		cout<<endl;
		while(cntx>lim){
//			printf("Reduce %d\n",x[cntx-1].val-b[x[cntx-1].id][1]);
			ans-=x[cntx-1].val-b[x[cntx-1].id][1];
			cntx--;
		}
	}else{
		if(cnty>lim){
			sort(y.begin(),y.end(),cmp);
			while(cnty>lim){
				ans-=y[cnty-1].val-b[y[cnty-1].id][1];
				cnty--;
			}
		}else{
			if(cntz>lim){
				sort(z.begin(),z.end(),cmp);
				while(cntz>lim){
					ans-=z[cntz-1].val-b[z[cntz-1].id][1];
					cntz--;
				}
			}
		}
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}

