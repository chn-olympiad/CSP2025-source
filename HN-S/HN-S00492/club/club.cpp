#include<bits/stdc++.h>
using namespace std;
int t,n,a[100001][4],b[100001],c,d,e,ans;
struct M{
	int x,id;
}aa[100001],bb[100001],cc[100001];
bool cmp(M xx,M yy){
	return xx.x<yy.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	for(cin>>t;t--;){
		ans=0;
		fill(a[0],a[100001],0);
		fill(b+0,b+100001,0);
		c=d=e=ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>a[i][2]){
				if(a[i][1]>a[i][3]){
					b[i]=1;
					c++;
				}else{
					b[i]=3;
					e++;
				}
			}else{
				if(a[i][2]>a[i][3]){
					b[i]=2;
					d++;
				}else{
					b[i]=3;
					e++;
				}
			}
		}
		if(c>n/2){
			for(int i=1;i<=n;i++){
				aa[i].x=min(a[i][1]-a[i][2],a[i][1]-a[i][3]);
				aa[i].id=i;
			}
			sort(aa+1,aa+n+1,cmp);
			for(int i=1;i<=c-n/2;i++){
				if(a[aa[i].id][2]>a[aa[i].id][3]){
					b[aa[i].id]=2;
				}else{
					b[aa[i].id]=3;
				}
			}
		}
		if(d>n/2){
			for(int i=1;i<=n;i++){
				bb[i].x=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
				bb[i].id=i;
			}
			sort(bb+1,bb+n+1,cmp);
			for(int i=1;i<=d-n/2;i++){
				if(a[bb[i].id][1]>a[bb[i].id][3]){
					b[bb[i].id]=1;
				}else{
					b[bb[i].id]=3;
				}
			}
		}
		if(e>n/2){
			for(int i=1;i<=n;i++){
				cc[i].x=min(a[i][3]-a[i][1],a[i][3]-a[i][2]);
				cc[i].id=i;
			}
			sort(cc+1,cc+n+1,cmp);
			for(int i=1;i<=e-n/2;i++){
				if(a[cc[i].id][1]>a[cc[i].id][2]){
					b[cc[i].id]=1;
				}else{
					b[cc[i].id]=2;
				}
			}
		}
		for(int i=1;i<=n;i++){
			ans+=a[i][b[i]];
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
