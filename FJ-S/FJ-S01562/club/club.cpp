#include<bits/stdc++.h>

using namespace std;

int n;

struct node{
	int x,y,z;
	int m1,m2,m3;
	int d1,d2,d3;
	int c1,c2,c3;
	int id;
}a[100001];

int b[4];

inline bool cmp(node A,node B){
	if(A.c1!=B.c1){
		return A.c1>B.c1;
	}
	else{
		if(A.m1!=B.m1)
			return A.m1>B.m1;
		else{
			if(A.c2!=B.c2)
				return A.c2>B.c2;
			else{
				if(A.m2!=B.m2)
					return A.m2>B.m2;
				else{
					if(A.c3!=B.c3)
						return A.c3>B.c3;
					else{
						if(A.m3!=B.m3)
							return A.m3>B.m3;
						else
							return A.id<B.id;
					}
				}
			}
		}
	}
}

inline void solve(){
	scanf("%d",&n);
	bool f1=true;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		if(a[i].y!=0||a[i].z!=0){
			f1=false;
		}
		int x1=a[i].x,y1=a[i].y,z1=a[i].z;
		a[i].id=i;
		if(x1>=y1&&y1>=z1){
			a[i].m1=x1;
			a[i].d1=1;
			a[i].m2=y1;
			a[i].d2=2;
			a[i].m3=z1;
			a[i].d3=3;
		}
		
		if(x1>=z1&&z1>=y1){
			a[i].m1=x1;
			a[i].d1=1;
			a[i].m2=z1;
			a[i].d2=3;
			a[i].m3=y1;
			a[i].d3=2;
		}
		
		if(z1>=x1&&x1>=y1){
			a[i].m1=z1;
			a[i].d1=3;
			a[i].m2=x1;
			a[i].d2=1;
			a[i].m3=y1;
			a[i].d3=2;
		}
		
		if(z1>=y1&&y1>=x1){
			a[i].m1=z1;
			a[i].d1=3;
			a[i].m2=y1;
			a[i].d2=2;
			a[i].m3=x1;
			a[i].d3=1;
		}
		
		if(y1>=x1&&x1>=z1){
			a[i].m1=y1;
			a[i].d1=2;
			a[i].m2=x1;
			a[i].d2=1;
			a[i].m3=z1;
			a[i].d3=3;
		}
		
		if(y1>=z1&&z1>=x1){
			a[i].m1=y1;
			a[i].d1=2;
			a[i].m2=z1;
			a[i].d2=3;
			a[i].m3=x1;
			a[i].d3=1;
		}
		
		a[i].c1=a[i].m1-a[i].m3;
		a[i].c2=max((a[i].c1-a[i].c2),(a[i].c2-a[i].c3));
		a[i].c3=min((a[i].c1-a[i].c2),(a[i].c2-a[i].c3));
	}
	if(f1==true){
		long long an=0;
		int aa[100001];
		for(int i=1;i<=n;i++)
			aa[i]=a[i].x;
		sort(aa+1,aa+n+1);
		int d=0;
		for(int i=n;i>=1;i--){
			if(d<n/2){
				an+=aa[i];
				d++;
			}
			else{
				printf("%lld\n",an);
				break;
			}
		}
	}
	else{
		sort(a+1,a+n+1,cmp);
	
		//for(int i=1;i<=n;i++){
		//	printf("%d %d %d\n",a[i].x,a[i].y,a[i].z);
		//}
		
		for(int i=1;i<=3;i++)
			b[i]=0;
		
		/*for(int i=1;i<=n;i++){
			printf("%d %d %d\n",a[i].m1,a[i].m2,a[i].m3);
			printf("%d %d %d\n",a[i].d1,a[i].d2,a[i].d3);
		}*/
		
		long long ans=0;
		
		int n1=n/2;
		//printf("%d\n",n1);
		for(int i=1;i<=n;i++){
			if(b[a[i].d1]<n1){
				b[a[i].d1]++;
				ans+=a[i].m1;
			}
			else{
				if(b[a[i].d2]<n1){
					b[a[i].d2]++;
					ans+=a[i].m2;
				}
				else{
					b[a[i].d3]++;
					ans+=a[i].m3;
				}
			}
		}
		//for(int i=1;i<=3;i++)
			//printf("%d ",b[i]);
		//cout<<'\n';
		
		printf("%lld\n",ans);
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	scanf("%d",&t);
	
	for(;t--;)
		solve();
}
