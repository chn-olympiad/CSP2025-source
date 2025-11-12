#include<bits/stdc++.h>
using namespace std;
struct node{
	int cha,biao;
}d[100005];
long long a[100005],b[100005],c[100005],e[100005];
//d[]=大数和中数的差,e[]=i人去了哪个岗位 
int aa,bb,cc;
long long T,n,ans;
bool cmp(node a1,node a2){
	return a1.cha<a2.cha;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		int k=n/2;
		bool flag=1;
		int maxn;
		ans=0;
		for(int i=1;i<=n;i++){
			a[i]=0;
			b[i]=0;
			c[i]=0;
			e[i]=0;
			d[i].cha=0;
			d[i].biao=0;
		}
		aa=0,bb=0,cc=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			d[i].biao=i;
			if(b[i]!=0||c[i]!=0){
				flag=0;
			}
			int ee=a[i],f=b[i],g=c[i];
			int efg=min(ee,min(f,g));
			if(efg==ee) {
				d[i].cha=max(f,g)-min(f,g);
				if(f>=g) maxn=2;
				else maxn=3;
			}
			else if(efg==f) {
				d[i].cha=max(ee,g)-min(ee,g);
				if(ee>=g) maxn=1;
				else maxn=3;
			}
			else if(efg==g) {
				d[i].cha=max(ee,f)-min(ee,f);
				if(ee>=f) maxn=1;
				else maxn=2;
			}
			if(maxn==1) e[i]=1,aa++,ans+=a[i];
			else if(maxn==2) e[i]=2,bb++,ans+=b[i];
			else if(maxn==3) e[i]=3,cc++,ans+=c[i];
		}
		sort(d+1,d+n+1,cmp);
		if(aa>n/2){
			int kkk=aa-n/2; 
			for(int i=1;i<=n;i++){
				if(e[d[i].biao]==1) ans-=d[i].cha,kkk--;
				if(kkk==0) break;
			}
		}
		else if(bb>n/2){
			int kkk=bb-n/2; 
			for(int i=1;i<=n;i++){
				if(e[d[i].biao]==2) ans-=d[i].cha,kkk--;
				if(kkk==0) break;
			}
		}
		else if(cc>n/2){
			int kkk=cc-n/2; 
			for(int i=1;i<=n;i++){
				if(e[d[i].biao]==3) ans-=d[i].cha,kkk--;
				if(kkk==0) break;
			}
		}
//		if(flag==1){
//			sort(a+1,a+n+1);
//			for(int i=n;i>n/2;i--){
//				ans+=a[i];
//			}
//			cout<<ans;
//		}
		cout<<ans<<endl;
	}
	return 0;
}

