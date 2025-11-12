#include<bits/stdc++.h>
using namespace std;
long long T,n,l[5],ans;
struct num{
	int d[5];
}a[100005];
struct mm{
	int d[5];
	int p1,p2,p3;
}b[100005];
int cmp(mm x,mm y){
	if(x.d[x.p1]==y.d[y.p1]){
		if(x.d[x.p2]==y.d[y.p2]) return x.d[x.p3]>y.d[y.p3];
		return x.d[x.p2]>y.d[y.p2];
	}
	return x.d[x.p1]>y.d[y.p1];
}
void dfs(long long i,long long s){
	if(i>n) ans=max(ans,s);
	else{
		for(int j=1;j<=3;j++){
			if(l[j]+1<=n/2){
				l[j]++;
				dfs(i+1,s+a[i].d[j]);
				l[j]--;
			}
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=-1;
		l[1]=l[2]=l[3]=0;
		cin>>n;
		if(n>30){
			ans=0;
			for(int i=1;i<=n;i++){
				cin>>b[i].d[1]>>b[i].d[2]>>b[i].d[3];
				if(b[i].d[1]>b[i].d[2]&&b[i].d[1]>b[i].d[3]){
					b[i].p1=1;
					if(b[i].d[2]>b[i].d[3]) b[i].p2=2,b[i].p3=3;
					else b[i].p2=3,b[i].p3=2;
				} 
				if(b[i].d[2]>b[i].d[1]&&b[i].d[2]>b[i].d[3]){
					b[i].p1=2;
					if(b[i].d[1]>b[i].d[3]) b[i].p2=1,b[i].p3=3;
					else b[i].p2=3,b[i].p3=1;
				}
				if(b[i].d[3]>b[i].d[2]&&b[i].d[1]<b[i].d[3]){
					b[i].p1=3;
					if(b[i].d[2]>b[i].d[1]) b[i].p2=2,b[i].p3=1;
					else b[i].p2=1,b[i].p3=2;
				}
			}
			sort(b+1,b+1+n,cmp);
			for(int i=1;i<=n;i++){
				if(l[b[i].p1]+1>n/2){
					if(l[b[i].p2]+1>n/2) l[b[i].p3]++,ans+=b[i].d[b[i].p3];
					else l[b[i].p2]++,ans+=b[i].d[b[i].p2];
				}else{
					l[b[i].p1]++,ans+=b[i].d[b[i].p1];
				}
			}
			cout<<ans<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++) cin>>a[i].d[1]>>a[i].d[2]>>a[i].d[3];
		dfs(1,0);
		cout<<ans<<"\n";
	}
	return 0;	
} 
