#include<bits/stdc++.h>
using namespace std;
int n,m,k,f[10010],c[15][10010];
long long ans=0;
struct qw{
	int x,y,w;
}a[1000010],b[1020100][2];
bool cmp(qw x,qw y){
	return x.w<y.w;
} 
int find(int x){
	if(f[x]!=x){
		f[x]=find(f[x]);
		return f[x];
	}
	return x;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].x>>a[i].y>>a[i].w;
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>c[i][j];
		}
	}
	for(int i=1;i<=n+1;i++){
			f[i]=i;
	}
	sort(a+1,a+m+1,cmp);
	int cnt=1;
	//需调整1，删变2，bug 
	for(int i=1;i<=m;i++){
		int ax=find(a[i].x),ay=find(a[i].y);
		if(ax==ay) continue;
		ans+=a[i].w;
		b[1][cnt].x=a[i].x;
		b[1][cnt].y=a[i].y;
		b[1][cnt].w=a[i].w;
		f[ax]=ay;
		cnt++;
	}
//	cout<<ans<<endl;
	for(int j=1;j<=k;j++){
		int ji=0;
		long long num=0;bool yong[20000]={};
		int s;cnt=1;
		for(int i=n;i<n*2;i++){
			b[j%2][i].x=j+n;
			b[j%2][i].y=i-n+1;
			b[j%2][i].w=c[j][i-n+1];	
		}
		
		for(int i=1;i<=n+15;i++){
			f[i]=i;
		}
		sort(b[j%2]+1,b[j%2]+n*2,cmp);
//		for(int i=1;i<n*2;i++){
//			cout<<b[1][i].x<<' ';
//			cout<<b[1][i].y<<' ';
//			cout<<b[1][i].w<<endl;
//		}
		for(int i=1;i<n+n;i++){
			int ax=find(b[j%2][i].x),ay=find(b[j%2][i].y);
			if(ax==ay) continue;
//			cout<<'*'<<b[j%2][i].x<<' '<<b[j%2][i].y<<' '<<ax<<' '<<ay<<' '<<i<<endl;
			if(!yong[b[j%2][i].x]&&b[j%2][i].x<=n) ji++;
			if(!yong[b[j%2][i].y]&&b[j%2][i].y<=n) ji++;
			yong[b[j%2][i].x]=1;
			yong[b[j%2][i].y]=1;
			num+=b[j%2][i].w;
			b[(j+1)%2][cnt].x=b[j%2][i].x;
			b[(j+1)%2][cnt].y=b[j%2][i].y;
			b[(j+1)%2][cnt].w=b[j%2][i].w;
			f[ax]=ay;
			cnt++;
			if(ji>n) break;
		}

		for(int i=n+1;i<=n+k;i++)
			if(yong[i]) num+=c[j][0];
//		cout<<ans<<' '<<num+c[j][0]<<endl;
		ans=min(ans,num);
	}
	cout<<ans;
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
