#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
struct node{
	int x,y,z,maxn,minn,mid;
}a[100005];
struct deno{
	int id,num,dj1,dj2;
}xx[100005],yy[100005],zz[100005];
bool cmp(deno l,deno r){
	if(l.dj1==r.dj1){
		if(l.dj2==r.dj2){
			return l.num<r.num;
		}else{
			return l.dj2<r.dj2;
		}
	}else{
		return l.dj1<r.dj1;
	}
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y>>a[i].z;
		ll sum=a[i].x+a[i].y+a[i].z;
		a[i].maxn=max(max(a[i].x,a[i].y),a[i].z);
		a[i].minn=min(min(a[i].x,a[i].y),a[i].z);
		a[i].mid=sum-a[i].maxn-a[i].minn;
	}
	int o=0,p=0,q=0;
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(a[i].maxn==a[i].x){
			o++;
			xx[o].num=a[i].maxn;
			xx[o].id=i;
			xx[o].dj1=a[i].maxn-a[i].mid;
			xx[o].dj2=a[i].maxn-a[i].minn;
		}else if(a[i].maxn==a[i].y){
			p++;
			yy[p].num=a[i].maxn;
			yy[p].id=i;
			yy[p].dj1=a[i].maxn-a[i].mid;
			yy[p].dj2=a[i].maxn-a[i].minn;
		}else{
			q++;
			zz[q].num=a[i].maxn;
			zz[q].id=i;
			zz[q].dj1=a[i].maxn-a[i].mid;
			zz[q].dj2=a[i].maxn-a[i].minn;
		}
	}
	if(o<=(n/2)&&p<=(n/2)&&q<=(n/2)){
		for(int i=1;i<=o;i++){
			ans+=xx[i].num;
		}
		for(int i=1;i<=p;i++){
			ans+=yy[i].num;
		}
		for(int i=1;i<=q;i++){
			ans+=zz[i].num;
		}
		cout<<ans<<endl;
	}else{
		sort(xx+1,xx+o+1,cmp);
		int ooo=1,ppp=1,qqq=1;
		while((o-ooo+1)>(n/2)){
			int idm=xx[ooo].id;
			xx[ooo].num=0;
			xx[ooo].id=0;
			xx[ooo].dj1=0;
			xx[ooo].dj2=0;
			if(((p<(n/2))&&(a[idm].y==a[idm].mid))||(q>=(n/2))){
				p++;
				yy[p].num=a[idm].y;
				yy[p].id=idm;
				yy[p].dj1=0;
				yy[p].dj2=a[idm].mid-a[idm].minn;
			}else{
				q++;
				zz[q].num=a[idm].z;
				zz[q].id=idm;
				zz[q].dj1=0;
				zz[q].dj2=0;
			}
			ooo++;
		}
		sort(yy+1,yy+p+1,cmp);
		while((p-ppp+1)>(n/2)){
			int idm=yy[ppp].id;
			yy[ppp].num=0;
			yy[ppp].id=0;
			yy[ppp].dj1=0;
			yy[ppp].dj2=0;
			if(((o<(n/2))&&(a[idm].x==a[idm].mid))||(q>=(n/2))){
				o++;
				xx[o].num=a[idm].x;
				xx[o].id=idm;
				xx[o].dj1=0;
				xx[o].dj2=a[idm].mid-a[idm].minn;
			}else{
				q++;
				zz[q].num=a[idm].z;
				zz[q].id=idm;
				zz[q].dj1=0;
				zz[q].dj2=0;
			}
			ppp++;
		}
		sort(zz+1,zz+q+1,cmp);
		while((q-qqq+1)>(n/2)){
			int idm=zz[qqq].id;
			zz[qqq].num=0;
			zz[qqq].id=0;
			zz[qqq].dj1=0;
			zz[qqq].dj2=0;
			if(((o<(n/2))&&(a[idm].x==a[idm].mid))||(p>=(n/2))){
				o++;
				xx[o].num=a[idm].x;
				xx[o].id=idm;
				xx[o].dj1=0;
				xx[o].dj2=a[idm].mid-a[idm].minn;
			}else{
				p++;
				yy[p].num=a[idm].y;
				yy[p].id=idm;
				yy[p].dj1=0;
				yy[p].dj2=0;
			}
			qqq++;
		}
		for(int i=ooo;i<=o;i++){
			ans+=xx[i].num;
		}
		for(int i=ppp;i<=p;i++){
			ans+=yy[i].num;
		}
		for(int i=qqq;i<=q;i++){
			ans+=zz[i].num;
		}
		cout<<ans<<endl;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
