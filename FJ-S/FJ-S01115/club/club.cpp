#include<bits/stdc++.h>
using namespace std;
int T,n;
int a[100005][4];
int e[4][100005];
int c[100005];
long long zn[105],ans;
struct node{
	int u,v,s,id;
}b[100005];
bool cmp(node x,node y){
	if(x.s==y.s) return x.u<y.u;
	return x.s<y.s;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(int t=1;t<=T;t++){
		memset(c,0,sizeof(c));
		memset(e,0,sizeof(e));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		ans=0;
		cin>>n;
		int len1=0;
		int len2=0;
		int len3=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]) e[1][++len1]=i;
			else if(a[i][2]>a[i][1]&&a[i][2]>a[i][3]) e[2][++len2]=i;
			else e[3][++len3]=i;
		}
		int len,z;
		for(int i=1;i<=len1;i++) ans+=a[e[1][i]][1];
		for(int i=1;i<=len2;i++) ans+=a[e[2][i]][2];
		for(int i=1;i<=len3;i++) ans+=a[e[3][i]][3];
		if(len1<=n/2&&len2<=n/2&&len3<=n/2){
			zn[t]=ans;
			continue;
		}
		if(len1>len2&&len1>len3) len=len1,z=1;
		else if(len2>len3&&len2>len3) len=len2,z=2;
		else len=len3,z=3;
		for(int i=1;i<=len;i++){
			b[i].id=i;
			b[i].u=a[e[z][i]][z];
//			cout<<b[i].u<<endl;
			if(z==1){
				b[i].v=a[e[z][i]][2];
				b[i].s=b[i].u-b[i].v;
			}
			if(z==2){
				b[i].v=a[e[z][i]][3];
				b[i].s=b[i].u-b[i].v;
			}
			if(z==3){
				b[i].v=a[e[z][i]][1];
				b[i].s=b[i].u-b[i].v;
			}
		}
		for(int i=1;i<=len;i++){
			b[len+i].id=i;
			b[len+i].u=a[e[z][i]][z];
			if(z==1){
				b[len+i].v=a[e[z][i]][3];
				b[len+i].s=b[len+i].u-b[len+i].v;
			}
			if(z==2){
				b[len+i].v=a[e[z][i]][1];
				b[len+i].s=b[len+i].u-b[len+i].v;
			}
			if(z==3){
				b[len+i].v=a[e[z][i]][2];
				b[len+i].s=b[len+i].u-b[len+i].v;
			}
		}
		sort(b+1,b+1+2*len,cmp);
		int cnt=0;
		for(int i=1;i<=2*len;i++){
			if(cnt==len-n/2) break;
			if(c[b[i].id]==1) continue;
			c[b[i].id]=1;
			ans-=b[i].u-b[i].v;
			cnt++;
		}
		zn[t]=ans;
	}
	for(int i=1;i<=T;i++) cout<<zn[i]<<endl;
	return 0;
} 
