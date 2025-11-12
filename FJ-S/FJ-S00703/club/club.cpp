#include<bits/stdc++.h>
using namespace std;
long long T,n;
long long bes[200005];
long long nex[200005];
long long x,y,z;
long long ans;
long long xx[100005],yy[100005],zz[100005];
struct jgt{
	long long num,d;
}a[100005];
bool cmp(jgt a,jgt b){
	return a.num<b.num;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		x=0,y=0,z=0,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			long long a,b,c;
			cin>>a>>b>>c;
			bes[i]=max(a,max(b,c));
			if(bes[i]==a) nex[i]=max(b,c),x++,xx[x]=i;
			else if(bes[i]==b) nex[i]=max(a,c),y++,yy[y]=i;
			else nex[i]=max(b,a),z++,zz[z]=i;
			ans+=bes[i];
		}
		if(x<=n/2&&y<=n/2&&z<=n/2){
			cout<<ans<<endl;
		}
		else{
			if(x>n/2){
				int nee=x-n/2;
				for(int i=1;i<=x;i++) a[i].num=bes[xx[i]]-nex[xx[i]];
				sort(a+1,a+x+1,cmp);
				for(int i=1;i<=nee;i++) ans-=a[i].num;
			}
			else if(y>n/2){
				int nee=y-n/2;
				for(int i=1;i<=y;i++) a[i].num=bes[yy[i]]-nex[yy[i]];
				sort(a+1,a+y+1,cmp);
				for(int i=1;i<=nee;i++) ans-=a[i].num;
			}
			else{
				int nee=z-n/2;
				for(int i=1;i<=z;i++) a[i].num=bes[zz[i]]-nex[zz[i]];
				sort(a+1,a+z+1,cmp);
				for(int i=1;i<=nee;i++) ans-=a[i].num;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
