#include<bits/stdc++.h>
using namespace std;
int t,n,a[500005][3],ans,k,num;
struct person{
	int a,b,c,d; 
	bool operator < (const person&w){
		return d<w.d;
	}
}p[500005];
int maxn[3];
bool b[500005];
int mid(int x){
	int q[3];
	q[1]=p[x].a;
	q[2]=p[x].b;
	q[3]=p[x].c;
	sort(q+1,q+4);
	return q[3]-q[2];
}
int find(int x){
	int ma=max(p[x].a,max(p[x].b,p[x].c));
	if(ma==p[x].a) return 1;
	if(ma==p[x].b) return 2;
	else return 3;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out",r,stdin);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>p[i].a>>p[i].b>>p[i].c;
			p[i].d=mid(i);
		}
		sort(p+1,p+1+n);
		for(int i=n;i>0;i--){
			k=i;
			maxn[find(i)]++;
			ans+=max(p[i].a,max(p[i].b,p[i].c));
			if(maxn[find(i)]==n/2) {
				num=find(i);
				if(num==1) for(int j=1;j<=n;j++) p[j].a=0;
				else if(num==2) for(int j=1;j<=n;j++) p[j].b=0;
				else for(int j=1;j<=n;j++) p[j].c=0;
				memset(maxn,0,sizeof(maxn));
				break;
			}
		}
		for(int i=1;i<k;i++){
			ans+=max(p[i].a,max(p[i].b,p[i].c));
		}
		cout<<ans<<'\n';
		ans=0;
	}
}
