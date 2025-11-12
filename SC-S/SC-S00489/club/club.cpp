#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;

int t,n,cur,sizpl,sizpm,sizpr,ans,cnt,posl=1,posm=1,posr=1;
struct stu{
	int num,val;
}pl[maxn],pr[maxn],pm[maxn];
struct st{
	int l,m,r;
}p[maxn];
bool ifisused[maxn];

int in(){
	int t=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		t=(t<<3)+(t<<1)+(c^48);
		c=getchar();
	}
	return t*f;
}

void out(int x){
	if(x<0) putchar('-'),x=-x;
	if(x<10) putchar(x^48);
	else out(x/10),putchar(x%10^48);
}

bool cmp(stu a,stu b){
	if(a.val!=0&&(p[a.num].l==0&&p[a.num].m==0)||(p[a.num].l==0&&p[a.num].r==0)||(p[a.num].r==0&&p[a.num].m==0))
		return 1;
	if(a.val==b.val) return a.num<b.num;
	return a.val>b.val;
}

void cle(int x){
	for(int i=0;i<=n;i++){
		pl[i].val=pm[i].val=pr[i].val=0;
		pl[i].num=pm[i].num=pr[i].num=0;
		ifisused[i]=0;
	}
	cur=0,sizpl=0,sizpm=0,sizpr=0;
	ans=0,cnt=0;
	posl=posm=posr=1;
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=in();
	while(t--){
		n=in();
		for(int i=1;i<=n;i++){
			pl[i].val=in(),pm[i].val=in(),pr[i].val=in();
			pl[i].num=pm[i].num=pr[i].num=i;
			p[i].l=pl[i].val;
			p[i].m=pm[i].val;
			p[i].r=pr[i].val;
		}
		sort(pl+1,pl+1+n,cmp);
		sort(pm+1,pm+1+n,cmp);
		sort(pr+1,pr+1+n,cmp);
		while(cnt<n){
			while(ifisused[pl[posl].num]) posl++;
			while(ifisused[pm[posm].num]) posm++;
			while(ifisused[pr[posr].num]) posr++;
			if(pl[posl].val>=max(pm[posm].val,pr[posr].val)){
				if(sizpl<n/2){
					cur=pl[posl].val,ifisused[pl[posl].num]=1,posl++,sizpl++;
				}
				else{
					if(pm[posm].val>=pr[posr].val){
						cur=pm[posm].val,ifisused[pm[posm].num]=1,posm++,sizpm++;
					}
					else{
						cur=pr[posr].val,ifisused[pr[posr].num]=1,posr++,sizpr++;
					}
				} 
			}
			else if(pm[posm].val>=max(pl[posl].val,pr[posr].val)){
				if(sizpm<n/2){
					cur=pm[posm].val,ifisused[pm[posm].num]=1,posm++,sizpm++;
				}
				else{
					if(pl[posl].val>=pr[posr].val){
						cur=pl[posl].val,ifisused[pl[posl].num]=1,posl++,sizpl++;
					}
					else{
						cur=pr[posr].val,ifisused[pr[posr].num]=1,posr++,sizpr++;
					}
				}
			}
			else{
				if(sizpr<n/2){
					cur=pr[posr].val,ifisused[pr[posr].num]=1,posr++,sizpr++;
				}
				else{
					if(pl[posl].val>=pm[posm].val){
						cur=pl[posl].val,ifisused[pl[posl].num]=1,posl++,sizpl++;
					}
					else{
						cur=pm[posm].val,ifisused[pm[posm].num]=1,posm++,sizpm++;
					}
				}
			}
			ans+=cur;
			cnt++;
		}
		out(ans),putchar('\n');
		cle(n);
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
*/