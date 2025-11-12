#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,z,est,er,p;
}; 
bool cmps(node a,node b){
	return a.est < b.est;
}
bool cmpj(node a,node b){
	return a.est > b.est;
}
bool cmp1(node a,node b){
	return a.x > b.x;
}
bool cmp2(node a,node b){
	return a.y > b.y;
}
bool cmp3(node a,node b){
	return a.z > b.z;
}
node a[100007];
node b[100007];
int r[7];
int r1[7];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;scanf("%d",&t);
	int n;
	while(t--){
		scanf("%d",&n);
		long long sum=0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(r,0,sizeof(r));
		memset(r1,0,sizeof(r1));
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			if(a[i].x >= a[i].y && a[i].x >= a[i].z){
				a[i].est=1;
				if(a[i].y >= a[i].z){
					a[i].er=2;
					a[i].p=3;
				}else{
					a[i].er=3;
					a[i].p=2;
				}
			}else if(a[i].y >= a[i].z){
				a[i].est=2;
				if(a[i].x >= a[i].z){
					a[i].er=1;
					a[i].p=3;
				}else{
					a[i].er=3;
					a[i].p=1;
				}
			}else{
				a[i].est=3;
				if(a[i].x >= a[i].y){
					a[i].er=1;
					a[i].p=2;
				}else{
					a[i].er=2;
					a[i].p=1;
				}
			}
		}	
		for(int i=1;i<=n;i++){
			if(a[i].est==1) r[1]++;
			else if(a[i].est==2) r[2]++;
			else r[3]++;
		}
		if(r[1] >= r[2] && r[1] >= r[3]){
			sort(a+1,a+1+n,cmps);
			sort(a+1,a+1+r[1],cmp1);
			for(int i=1;i<=r[1];i++){
				if(i<=n/2){
					sum+=a[i].x;
					r1[1]=i;
				}else{
					a[i].est = a[i].er;
					a[i].er = a[i].p;
				}
			}
			sort(a+1+r1[1],a+1+r1[1]+r[2],cmp2);
			for(int i=r1[1]+1;i<=r[1]+r[2];i++){
				if((i-r1[1])<=n/2){
					sum+=a[i].y;
					r1[2]=i-r1[1];
				}else{
					a[i].est = a[i].er;
					a[i].er = a[i].p;
				}
			}
			sort(a+1+r1[1]+r1[2],a+1+n,cmp3);
			for(int i=r1[1]+r1[2]+1;i<=n;i++){
				sum+=a[i].z;
			}
			cout<<sum<<'\n';
		}else if(r[3] >= r[2] && r[3]>=r[1]){
			sort(a+1,a+1+n,cmpj);
			sort(a+1,a+1+r[3],cmp3);
			for(int i=1;i<=r[3];i++){
				if(i<=n/2){
					sum+=a[i].z;
					r1[3]=i;
				}else{
					a[i].est = a[i].er;
					a[i].er = a[i].p;
				}
			}
			sort(a+1+r1[3],a+1+r1[3]+r[2],cmp2);
			for(int i=r1[3]+1;i<=r[3]+r[2];i++){
				if((i-r1[3])<=n/2){
					sum+=a[i].y;
					r1[2]=i-r1[3];
				}else{
					a[i].est = a[i].er;
					a[i].er = a[i].p;
				}
			}
			sort(a+1+r1[3]+r1[2],a+1+n,cmp1);
			for(int i=r1[3]+r1[2]+1;i<=n;i++){
				sum+=a[i].x;
			}
			cout<<sum<<'\n';
		}else{
			int o=1;
			for(int i=1;i<=n;i++){
				if(a[i].est==2){
					b[o]=a[i];
					o++;	
				}
			}
			for(int i=1;i<=n;i++){
				if(a[i].est==1){
					b[o]=a[i];
					o++;
				}
			}
			for(int i=1;i<=n;i++){
				if(a[i].est==3){
					b[o]=a[i];
					o++;
				}
			}
			sort(b+1,b+1+r[2],cmp2);
			for(int i=1;i<=r[2];i++){
				if(i<=n/2){
					sum+=b[i].y;
					r1[2]=i;
				}else{
					b[i].est = b[i].er;
					b[i].er = b[i].p;
				}
			}
			sort(b+1+r1[2],b+1+r1[2]+r[1],cmp2);
			for(int i=r1[2]+1;i<=r[2]+r[1];i++){
				if((i-r1[2])<=n/2){
					sum+=b[i].x;
					r1[2]=i-r1[3];
				}else{
					b[i].est = b[i].er;
					b[i].er = b[i].p;
				}
			}
			sort(b+1+r1[2]+r1[1],b+1+n,cmp1);
			for(int i=r1[2]+r1[1]+1;i<=n;i++){
				sum+=b[i].z;
			}
			cout<<sum<<'\n';
		}
		
	}
	return 0;
}
