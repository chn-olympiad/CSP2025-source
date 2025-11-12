#include<bits/stdc++.h>
using namespace std;
struct tr{
	long long v,to,w,kd;
}a[5001000];
long long n,m,k; 
long long f[31000],cont[31000],kw[30];
bool fg[30];
long long sd;
bool cmp(tr a,tr b){
	return a.w<b.w;
}
long long fd(long long x){
	if(f[x]==x)return f[x];
	return f[x]=fd(x);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(long long i=1;i<=n+k;i++){
		f[i]=i;
	}
//	cout<<m<<endl; 
	for(long long i=1;i<=m;i++){
		long long x,y,z;
		cin>>x>>y>>z;
		a[i].v=x;
		a[i].to=y;
		a[i].w=z;
		a[i].kd=-1;
	//	if(i%10000==0)cout<<i<<endl;
	}//cout<<1<<endl;
	long long l=m;
	for(long long i=1;i<=k;i++){
		long long x;cin>>x;
		kw[i]=x;
		for(long long j=1;j<=n;j++){
			cin>>cont[j];
		}
		for(long long j=1;j<=n;j++){
			for(long long k=j+1;k<=n;k++){
				a[++l].v=j;
				a[l].to=k;
				a[l].w=cont[j]+cont[k]+x;
				a[l].kd=i;
			//	cout<<l<<endl;
			}
		}
	}
//	cout<<1<<endl;
	long long cnt=0,sum=0;
	while(cnt<n){
		sd+=n;
		sort(a+1,a+l+1,cmp);
//	/	cout<<2<<endl;
		for(long long i=1;i<=l;i++){
			sd++;
			long long x=fd(a[i].v),y=fd(a[i].to);
			//cout<<x<<' '<<y<<endl;
			//cout<<a[i].v<<' '<<a[i].to<<' '<<a[i].w<<' '<<a[i].kd<<endl;
			if(x!=y){
				f[y]=x;
				cnt++;sum+=a[i].w;
				if(cnt==n-1){
					cout<<sum;
					return 0;
				}
			//	cout<<a[i].v<<' '<<a[i].to<<' '<<a[i].w<<' '<<a[i].kd<<endl;
				if(a[i].kd!=-1&&fg[a[i].kd]==0){
					for(long long j=i+1;j<=l;j++)
						if(a[j].kd==a[i].kd)sd++,a[j].w-=kw[a[i].kd];
					fg[a[i].kd]=1;
					break;
				}
				a[i].w=INT_MAX;
			}	
		}
	//	cout<<cnt<<endl;
	}
	return 0;
}
//1000000
