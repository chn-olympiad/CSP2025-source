#include<bits/stdc++.h>
using namespace std;
struct stu{
	int x[4],k;
}g[1000000],a[1000000],b[1000000],c[1000000];
int t,n,rn,an,bn,cn,sum,st[1000000];
bool cmp(stu a,stu b){
	if(a.x[1]!=b.x[1])return a.x[1]>b.x[1];
	else{
		return max(a.x[2],a.x[3])<max(b.x[2],b.x[3]);
	} 
}
bool cmpa(stu a,stu b){
	if(a.x[2]!=b.x[2])return a.x[2]>b.x[2];
	else{
		return max(a.x[1],a.x[3])<max(b.x[1],b.x[3]);
	} 
}
bool cmpb(stu a,stu b){
	if(a.x[3]!=b.x[3])return a.x[3]>b.x[3];
	else{
		return max(a.x[1],a.x[2])<max(b.x[1],b.x[2]);
	} 
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		rn=n/2;
		for(int i=1;i<=n;i++){
			cin>>g[i].x[1]>>g[i].x[2]>>g[i].x[3];
			g[i].k=i;
		}
		sort(g+1,g+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(i<=rn)an+=g[i].x[1];
			a[i]=g[i];
		}
		sort(g+1,g+n+1,cmpa);
		for(int i=1;i<=n;i++){
			if(i<=rn)bn+=g[i].x[2];
			b[i]=g[i];
		}
		sort(g+1,g+n+1,cmpb);
		for(int i=1;i<=n;i++){
			if(i<=rn)cn+=g[i].x[3];
			c[i]=g[i];
		}
		if(an>bn && an>cn){
			for(int i=1;i<=rn;i++){
				sum+=a[i].x[1];
				st[a[i].k]=1;
			}
			for(int i=1;i<=n;i++){
				int x=0,y=0;
				for(int j=1;j<=n;j++){
					if(st[b[j].k]!=1){
						sum+=b[j].x[2];
						st[b[j].k]=1;
						break;
					}
				}
				for(int j=1;j<=n;j++){
					if(st[c[j].k]!=1){
						sum+=c[j].x[3];
						st[c[j].k]=1;
						
						break;
					}
				}
				x=y=0;
			}
		}
		else if(bn>an && bn>cn){
			for(int i=1;i<=rn;i++){
				sum+=b[i].x[2];
				st[b[i].k]=1;
			}
			for(int i=1;i<=n;i++){
				int x=0,y=0;
				for(int j=1;j<=n;j++){
					if(st[a[j].k]!=1){
						sum+=a[j].x[1];
						st[a[j].k]=1;
						break;
					}
				}
				for(int j=1;j<=n;j++){
					if(st[c[j].k]!=1){
						sum+=c[j].x[3];
						st[c[j].k]=1;
						
						break;
					}
				}
				x=y=0;
			}
		}
		else if(cn>bn && cn>an){
			for(int i=1;i<=rn;i++){
				sum+=c[i].x[3];
				st[c[i].k]=1;
			}
			for(int i=1;i<=n;i++){
				int x=0,y=0;
				for(int j=1;j<=n;j++){
					if(st[b[j].k]!=1){
						sum+=b[j].x[2];
						st[b[j].k]=1;
						break;
					}
				}
				for(int j=1;j<=n;j++){
					if(st[a[j].k]!=1){
						sum+=a[j].x[1];
						st[a[j].k]=1;
						
						break;
					}
				}
				x=y=0;
			}
		}
		cout<<sum<<endl;
		sum=0;
		memset(st,0,sizeof(st));
	}
	return 0;
} 
