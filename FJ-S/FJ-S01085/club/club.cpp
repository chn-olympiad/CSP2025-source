#include <bits/stdc++.h>
using namespace std;
int t,ans=0;
int a[100005][4],b[100005],c[100005],d[100005];
int cnt1,cnt2,cnt3;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while (t--){
		ans=0;
		int n;
		cin>>n;
		bool q=true,w=true,e=true;
		if (n==2){
			int x1,y1,z1,x2,y2,z2;
			cin>>x1>>y1>>z1>>x2>>y2>>z2;
			int p1=x1+y2,p2=x1+z2,p3=y1+x2,p4=y1+z2,p5=z1+x2,p6=z1+y2;
			int u[6]={p1,p2,p3,p4,p5,p6};
			sort(u,u+6,cmp);
			cout<<u[0]<<endl;
			continue;
		}else{
			for (int i=1;i<=n;i++){
				cin>>a[i][1]>>a[i][2]>>a[i][3];
				b[i]=a[i][1];
				c[i]=a[i][2];
				d[i]=a[i][3];
				if (a[i][1]!=0){
					e=false;
				}
				if (a[i][2]!=0){
					q=false;
				}
				if (a[i][3]!=0){
					w=false;
				}
			}
			if (q==true && w==true){
				sort(b+1,b+1+n,cmp);
				for  (int i=1;i<=n/2;i++){
					ans+=b[i];
				}
				cout<<ans<<endl;
				continue; 
			}else if (q==true && e==true){
				sort(d+1,d+1+n,cmp);
				for  (int i=1;i<=n/2;i++){
					ans+=d[i];
				}
				cout<<ans<<endl;
				continue; 
			}else if (w==true && e==true){
				sort(c+1,c+1+n,cmp);
				for  (int i=1;i<=n/2;i++){
					ans+=c[i];
				}
				cout<<ans<<endl;
				continue; 
			}else{
				for (int i=1;i<=n;i++){
					int maxn=0;
					int id=-1;
					if (a[i][1]>maxn){
						maxn=a[i][1];
						id=1;
					}
					if (a[i][2]>maxn){
						maxn=a[i][2];
						id=2;
					}
					if (a[i][3]>maxn){
						maxn=a[i][3];
						id=3;
					}
					if (id==1 && cnt1<n/2){
						cnt1++;
						ans+=maxn;
					}
					if (id==2 && cnt2<n/2){
						cnt2++;
						ans+=maxn;
					}
					if (id==3 && cnt3<n/2){
						cnt3++;
						ans+=maxn;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
