#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
struct man{
	int d[4];
	int f,s;
}a[100005];
man l[4][100005];
int l1,l2,l3,ans,c1,c2,c3;
bool cmp(man a,man b){
	if(a.d[c1]!=b.d[c1]) return a.d[c1]>b.d[c1];
	if(a.d[c2]!=b.d[c2]) return a.d[c2]<b.d[c2];
	if(a.d[c3]!=b.d[c3]) return a.d[c3]<b.d[c3];
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(;t>0;t--){
		int n;
		l1=l2=l3=ans=c1=c2=c3=0;
		int o1=0,o2=0;
		memset(l,0,sizeof(l));
		memset(a,0,sizeof(a));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].d[1]>>a[i].d[2]>>a[i].d[3];
			if(a[i].d[2]!=0) o1=1;
			if(a[i].d[3]!=0) o2=1;
			if(a[i].d[1]>a[i].d[2]){//´óÐ¡ÆÀÅÐ 
				if(a[i].d[2]>a[i].d[3]){
					a[i].f=1;
					a[i].s=2;
				}else if(a[i].d[1]>a[i].d[3]){
					a[i].f=1;
					a[i].s=3;
				}else{
					a[i].f=3;
					a[i].s=1;
				}
			}else{
				if(a[i].d[1]>a[i].d[3]){
					a[i].f=2;
					a[i].s=1;
				}else if(a[i].d[2]>a[i].d[3]){
					a[i].f=2;
					a[i].s=3;
				}else{
					a[i].f=3;
					a[i].s=2;
				}
			}
		}
		if(o1==0&&o2==0){
			c1=1;
			sort(a,a+n,cmp);
			for(int i=1;i<=n/2;i++) ans+=a[i].d[1];
			cout<<ans<<endl;
			continue;
		}else if(o2==0){
			int ans2=0;
			c1=1,c2=2;
			sort(a,a+n,cmp);
			for(int i=1;i<=n/2;i++) ans+=a[i].d[1];
			for(int i=n/2+1;i<=n;i++) ans+=a[i].d[2];
			c1=2,c2=1;
			sort(a,a+n,cmp);
			for(int i=1;i<=n/2;i++) ans2+=a[i].d[2];
			for(int i=n/2+1;i<=n;i++) ans2+=a[i].d[1];
			ans=max(ans,ans2);
			cout<<ans<<endl;
		} 
	}
	return 0;
}
