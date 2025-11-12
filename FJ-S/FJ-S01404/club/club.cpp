#include<bits/stdc++.h>
using namespace std;
int t,l[100005],m[100005],r[100005],masn[100005],tot[100005],lv,mv,rv,sum,la,ra,ma;
bool cmp(int x,int y){
	return x>y;
}
struct st{
	int a,b,c,maxn,minn,mddl;
}p[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(masn,0,sizeof(masn));
		memset(p,0,sizeof(p));
		sum=0,lv=0,mv=0,rv=0,la=0,ma=0,ra=0;
		int minnl=-1,minnr=-1,minnm=-1;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>l[i]>>m[i]>>r[i];
			p[i].a=l[i],p[i].b=m[i],p[i].c=r[i];
			masn[i]=max({l[i],r[i],m[i]});
			p[i].minn=min({l[i],r[i],m[i]});
			p[i].maxn=masn[i];
			if(l[i]>=m[i]&&l[i]>=r[i]){
				la++;
				minnl=min(minnl,l[i]);
			}
			else if(m[i]>=l[i]&&m[i]>=r[i]){
				ma++;
				minnm=min(minnm,m[i]);
			}
			else if(r[i]>=l[i]&&r[i]>=m[i]){
				ra++;
				minnr=min(minnr,r[i]);
			}
			if(l[i]!=0)lv=1;
			if(m[i]!=0)mv=1;
			if(r[i]!=0)rv=1;
		} 
		if(lv==1&&mv==0&&rv==0){
			sort(l+1,l+1+n,cmp);
			for(int i=1;i<=n/2;i++){
				sum+=l[i];
			}
			cout<<sum<<endl;
		}
		else if(la<=n/2&&ma<=n/2&&ra<=n/2){
			for(int i=1;i<=n;i++){
				sum+=masn[i];
			}
			cout<<sum<<endl;
		}
		else if(lv==1&&mv==1&&rv==0){
			for(int i=1;i<=n;i++){
				tot[i]=l[i]-m[i];
				sum+=l[i];
			}
			sort(tot+1,tot+1+n);
			for(int i=1;i<=n/2;i++){
				sum-=tot[i];
			}
			cout<<sum<<endl;
		}
	}
	return 0;
} 
