#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
struct n{
	int xb,w,xb1,xb2,xb3,w1,w2,w3;
}s[100000][4],f[100000];
bool cmp(n x,n y){
	return x.w>y.w;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t,n,q,x[4],sum[6],p[100000]={};
	int a[10000][5]={};
	scanf("%lld",&t);
	for(int o=1;o<=t;o++){
		cin>>n;
		q=n/2;
		//cout<<q<<endl;
		for(long long i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			int h1=a[i][1],h2=a[i][2],h3=a[i][3],h4,h5;
			//cout<<a[i][1]<<a[i][2]<<a[i][3];
			h4=max(h1,h2);
			h5=max(h1,h3);
			if(h4==h5){
				p[i]=max(h2,h3);
			}else p[i]=min(h4,h5);
			
			//p[i]=max(h4=max(h1,h2),h5=max(h2,h3));
			s[i][1].w=a[i][1]-p[i];
			s[i][1].xb=1;
			s[i][2].w=a[i][2]-p[i];
			s[i][2].xb=2;
			s[i][3].w=a[i][3]-p[i];
			s[i][3].xb=3;
			sort(s[i]+1,s[i]+4,cmp);
			for(int k=1;k<=n;k++){
				f[k].w=s[k][1].w;
				f[k].w2=s[k][2].w;
				f[k].w3=s[k][3].w;
				f[k].xb1=s[k][1].xb;
				f[k].xb2=s[k][2].xb;
				f[k].xb3=s[k][3].xb;
			}
			sort(f+1,f+4,cmp);	
		}
		
		//cout<<p[1]<<p[2]<<p[3]<<p[4]<<endl;
		for(int j=1;j<=n;j++){
			if(x[f[j].xb1]+1<=q){
				sum[o]+=f[j].w+p[j];
				//cout<<s[j][1].w+p[j]<<"j:"<<1;
				x[f[j].xb1]++;
			}else if(x[f[j].xb2]+1<=q){
				sum[o]+=f[j].w2+p[j];
				//cout<<s[j][2].w+p[j]<<"j:"<<2;
				x[f[j].xb2]++;
			}else{
				sum[o]+=f[j].w3+p[j];
				//cout<<s[j][3].w+p[j]<<"j:"<<3;
				x[f[j].xb3]++;
			}
		}
		cout<<sum[o]<<"\n";
		x[1]=0,x[2]=0,x[3]=0;
		for(int d=1;d<=n;d++)p[d]=0;
	}
		 
	return 0;
}
